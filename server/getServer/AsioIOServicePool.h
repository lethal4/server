#pragma once
#include <vector>
#include <boost/asio.hpp>
#include "Singleton.h"
class AsioIOServicePool :public Singleton<AsioIOServicePool>//CRTP奇异递归模板
{
	friend Singleton<AsioIOServicePool>;
public:
	using IOService = boost::asio::io_context;//重命名
	using Work = boost::asio::io_context::work;//上下文，如果io_context调用发现没有方法会直接返回，
	//用work绑定io_context在没有任何事件的情况下不会自动退出（保持轮询状态）；
	using WorkPtr = std::unique_ptr<Work>;
	~AsioIOServicePool();
	AsioIOServicePool(const AsioIOServicePool&) = delete;//拷贝构造
	AsioIOServicePool& operator=(const AsioIOServicePool&) = delete;//拷贝赋值
	// 使用 round-robin 的方式返回一个 io_service
	boost::asio::io_context& GetIOService();
	void Stop();//回收资源，通知挂起线程继续
private:
	AsioIOServicePool(std::size_t size = 2/*std::thread::hardware_concurrency()*/);
	//确认CPU核数，利用多核优势，但是2足够
	std::vector<IOService> _ioServices;
	std::vector<WorkPtr> _works;//配套IOService
	std::vector<std::thread> _threads;//有多少上下文就配套多少个线程
	std::size_t  _nextIOService;//索引，返回下一个ioService索引 轮询方式
};

