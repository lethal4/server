#pragma once
#include "const.h"
class HttpConnection;
typedef std::function<void(std::shared_ptr<HttpConnection>)>HttpHandler;
//����һ������������
class LogicSystem :public Singleton<LogicSystem>
{
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem() {};
	bool HandleGet(std::string, std::shared_ptr<HttpConnection>);
	// url ����ָ��
	void RegGet(std::string, HttpHandler handler);
	//ע��ֻ��Ҫע��string url�ͻص�������˭
	void RegPost(std::string url, HttpHandler handler);
	//port
	bool HandlePost(std::string, std::shared_ptr<HttpConnection>);
private:
	LogicSystem();
	std::map < std::string, HttpHandler> _post_handlers;
	std::map < std::string, HttpHandler> _get_handlers;
	//����get post����ļ���
};

