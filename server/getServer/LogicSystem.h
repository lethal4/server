#pragma once
#include "const.h"
class HttpConnection;
typedef std::function<void(std::shared_ptr<HttpConnection>)>HttpHandler;
//定义一个函数处理器
class LogicSystem :public Singleton<LogicSystem>
{
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem() {};
	bool HandleGet(std::string, std::shared_ptr<HttpConnection>);
	// url 智能指针
	void RegGet(std::string, HttpHandler handler);
	//注册只需要注册string url和回调函数是谁
	void RegPost(std::string url, HttpHandler handler);
	//port
	bool HandlePost(std::string, std::shared_ptr<HttpConnection>);
private:
	LogicSystem();
	std::map < std::string, HttpHandler> _post_handlers;
	std::map < std::string, HttpHandler> _get_handlers;
	//处理get post请求的集合
};

