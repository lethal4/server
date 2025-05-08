#include "AsioIOServicePool.h"
#include <iostream>
using namespace std;
AsioIOServicePool::AsioIOServicePool(std::size_t size) :_ioServices(size),
_works(size), _nextIOService(0) {//不支持拷贝构造的需要放在初始化列表进行操作
	for (std::size_t i = 0; i < size; ++i) {
		_works[i] = std::unique_ptr<Work>(new Work(_ioServices[i]));//将裸指针交给unique_ptr管理后传递给work
	}

	//遍历多个ioservice，创建多个线程，每个线程内部启动ioservice
	for (std::size_t i = 0; i < _ioServices.size(); ++i) {
		_threads.emplace_back([this, i]() {//把ioServices交给work管理保证ioService不会退出
			_ioServices[i].run();//让服务运行 
			});
	}
}

AsioIOServicePool::~AsioIOServicePool() {
	Stop();//我创建的资源由我自己回收
	std::cout << "AsioIOServicePool destruct" << endl;
}

boost::asio::io_context& AsioIOServicePool::GetIOService() {
	auto& service = _ioServices[_nextIOService++];
	if (_nextIOService == _ioServices.size()) {
		_nextIOService = 0;//轮换使用线程
	}
	return service;
}

void AsioIOServicePool::Stop() {
	//因为仅仅执行work.reset并不能让iocontext从run的状态中退出
	//当iocontext已经绑定了读或写的监听事件后，还需要手动stop该服务。
	for (auto& work : _works) {
		work->get_io_context().stop();//把服务先停止
		work.reset();//变成空指针，回收io_context,随后run会都返回
	}
	for (auto& t : _threads) {
		t.join();
	}
}