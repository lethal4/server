#include "CServer.h"
#include "AsioIOServicePool.h"
#include "HttpConnection.h"
CServer::CServer(boost::asio::io_context& ioc, unsigned short& port) :_ioc(ioc), _acceptor(ioc, tcp::endpoint(tcp::v4(), port)) {

}
void CServer::Start() {
	auto self = shared_from_this();
	//����ָ�룬����
	auto& io_context = AsioIOServicePool::GetInstance()->GetIOService();
	std::shared_ptr<HttpConnection> new_con = std::make_shared<HttpConnection>(io_context);
	_acceptor.async_accept(new_con->GetSocket(), [self, new_con](beast::error_code ec) {
		try {	//_socket����ʹ�����÷�ֹ����������
			//Ϊ�˰�ȫ���ʹ��try catch
			//��������socket����
			if (ec)
			{
				self->Start();
				return;//�������
			}
			new_con->Start();
			self->Start();
		}
		catch (std::exception& exp) {

		}
		});
}