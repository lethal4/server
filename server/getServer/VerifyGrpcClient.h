#pragma once
#include <grpcpp/grpcpp.h>
#include "message.grpc.pb.h"

#include "const.h"
#include "Singleton.h"
//通过单例模式通信
using grpc::Channel;
using grpc::Status;
//状态
using grpc::ClientContext;
//上下文
using message::GetVarifyReq;
//得到
using message::GetVarifyRsp;
//回包
using message::VarifyService;
//服务，直接使用项目服务
class RPConPool {
public:
	RPConPool(size_t poolsize, std::string host, std::string port) :
		poolSize_(poolsize), host_(host), port_(port), b_stop_(false) {
		//池子
		for (size_t i = 0; i < poolSize_; i++) {
			std::shared_ptr<Channel> channel = grpc::CreateChannel(host + ":" + port, grpc::InsecureChannelCredentials());
			//智能指针会加入到stub_中，channel会作为一个通道来通信
			connections_.push(VarifyService::NewStub(channel));//接受右端时采取移动构造资源，unique_ptr不支持拷贝构造
			//创建信使
		}
	}
	~RPConPool() {
		std::lock_guard<std::mutex> lock_(mutex_);//加锁
		Close();//先通知其他线程这个池子要回收了
		while (!connections_.empty()) {
			connections_.pop();
		}
	}

	void Close() {
		//回收资源得告诉其他线程
		b_stop_ = true;
		cond_.notify_all();
	}
	std::unique_ptr<VarifyService::Stub> getConnection() {
		std::unique_lock<std::mutex> lock(mutex_);//加锁
		cond_.wait(lock, [this]() {//lambda 不懂
			if (b_stop_) {
				return true;
			}
			return !connections_.empty();
			});
		if (b_stop_) {
			return nullptr;
		}

		std::unique_ptr<VarifyService::Stub> context = std::move(connections_.front());////////不确定是不是,auto无法使用,出现错误可以从此处推断
		connections_.pop();
		return context;
	}

	void returnConnection(std::unique_ptr<VarifyService::Stub> context) {
		std::lock_guard<std::mutex> lock(mutex_);
		if (b_stop_) {
			return;
		}

		connections_.push(std::move(context));
		cond_.notify_one();//返回一个就通知一个连接
	}
private:
	std::atomic<bool>b_stop_;//判断需不需要回收
	size_t poolSize_;
	std::string host_;
	std::string port_;
	std::queue<std::unique_ptr<VarifyService::Stub>> connections_;
	std::mutex mutex_;
	std::condition_variable cond_;
};
class VerifyGrpcClient :public Singleton<VerifyGrpcClient>//grpc通信类
{							//使用先前封装好的单例Singleton
	friend class Singleton<VerifyGrpcClient>;
	//让单例能够访问自己的私有成员
public:
	~VerifyGrpcClient() {
	}
	GetVarifyRsp GetvarifyCode(std::string email) {
		ClientContext context;
		//客户端上下文
		GetVarifyRsp reply;
		//回包
		GetVarifyReq request;
		//请求
		request.set_email(email);
		//设置email
		auto stub = pool_->getConnection();
		Status status = stub->GetVarifyCode(&context, request, &reply);
		if (status.ok()) {
			pool_->returnConnection(std::move(stub));
			return reply;
		}
		else
		{
			pool_->returnConnection(std::move(stub));
			reply.set_error(ErrorCodes::RPCFailed);
			//传回错误
			return reply;
		}

	}
private:
	VerifyGrpcClient();

	std::unique_ptr<RPConPool> pool_;
};

