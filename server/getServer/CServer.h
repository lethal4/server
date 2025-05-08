#pragma once
#include "const.h"
#include "HttpConnection.h"
class CServer :public std::enable_shared_from_this<CServer>
{//奇异递归模板
public:
	CServer(boost::asio::io_context& ioc, unsigned short& port);
	//上下文  端口
	void Start();
private:
	tcp::acceptor _acceptor;
	net::io_context& _ioc;
	//链接对端信息，可复用
};

