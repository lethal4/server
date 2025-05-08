#pragma once
#include "const.h"
class HttpConnection :public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	HttpConnection(boost::asio::io_context& ioc);
	//需要一个socket构造
	void Start();
	tcp::socket& GetSocket() {
		return _socket;
	}
private:
	//http发送和接受存在一个超时检测，所以需要启动一个定时器来测试时间，长时间未接受辨别为掉线
	void CheckDeadline();
	void WriteResponse();
	void HandleReq();
	tcp::socket _socket;
	//定义一个数组接受对面发来的变量
	//设定为8K缓冲区
	beast::flat_buffer _buffer{ 8192 };
	http::request<http::dynamic_body> _request;
	//可以接受各种请求  dynamic动态
	http::response<http::dynamic_body> _response;
	net::steady_timer deadline_{
		//定时器 通过事件轮询来操作
		_socket.get_executor(),std::chrono::seconds(60)

	};
	void PreParseGetParam();
	std::string _get_url;
	std::unordered_map<std::string, std::string> _get_params;
};

