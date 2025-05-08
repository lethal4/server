#pragma once
#include "const.h"
class HttpConnection :public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	HttpConnection(boost::asio::io_context& ioc);
	//��Ҫһ��socket����
	void Start();
	tcp::socket& GetSocket() {
		return _socket;
	}
private:
	//http���ͺͽ��ܴ���һ����ʱ��⣬������Ҫ����һ����ʱ��������ʱ�䣬��ʱ��δ���ܱ��Ϊ����
	void CheckDeadline();
	void WriteResponse();
	void HandleReq();
	tcp::socket _socket;
	//����һ��������ܶ��淢���ı���
	//�趨Ϊ8K������
	beast::flat_buffer _buffer{ 8192 };
	http::request<http::dynamic_body> _request;
	//���Խ��ܸ�������  dynamic��̬
	http::response<http::dynamic_body> _response;
	net::steady_timer deadline_{
		//��ʱ�� ͨ���¼���ѯ������
		_socket.get_executor(),std::chrono::seconds(60)

	};
	void PreParseGetParam();
	std::string _get_url;
	std::unordered_map<std::string, std::string> _get_params;
};

