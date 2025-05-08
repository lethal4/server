#include "CServer.h"
#include "AsioIOServicePool.h"
#include "HttpConnection.h"
CServer::CServer(boost::asio::io_context& ioc, unsigned short& port) :_ioc(ioc), _acceptor(ioc, tcp::endpoint(tcp::v4(), port)) {

}
void CServer::Start() {
	auto self = shared_from_this();
	//智能指针，共享
	auto& io_context = AsioIOServicePool::GetInstance()->GetIOService();
	std::shared_ptr<HttpConnection> new_con = std::make_shared<HttpConnection>(io_context);
	_acceptor.async_accept(new_con->GetSocket(), [self, new_con](beast::error_code ec) {
		try {	//_socket不能使用引用防止被其他调用
			//为了安全起见使用try catch
			//出错即放弃socket链接
			if (ec)
			{
				self->Start();
				return;//防御编程
			}
			new_con->Start();
			self->Start();
		}
		catch (std::exception& exp) {

		}
		});
}