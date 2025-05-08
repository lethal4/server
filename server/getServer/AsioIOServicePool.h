#pragma once
#include <vector>
#include <boost/asio.hpp>
#include "Singleton.h"
class AsioIOServicePool :public Singleton<AsioIOServicePool>//CRTP����ݹ�ģ��
{
	friend Singleton<AsioIOServicePool>;
public:
	using IOService = boost::asio::io_context;//������
	using Work = boost::asio::io_context::work;//�����ģ����io_context���÷���û�з�����ֱ�ӷ��أ�
	//��work��io_context��û���κ��¼�������²����Զ��˳���������ѯ״̬����
	using WorkPtr = std::unique_ptr<Work>;
	~AsioIOServicePool();
	AsioIOServicePool(const AsioIOServicePool&) = delete;//��������
	AsioIOServicePool& operator=(const AsioIOServicePool&) = delete;//������ֵ
	// ʹ�� round-robin �ķ�ʽ����һ�� io_service
	boost::asio::io_context& GetIOService();
	void Stop();//������Դ��֪ͨ�����̼߳���
private:
	AsioIOServicePool(std::size_t size = 2/*std::thread::hardware_concurrency()*/);
	//ȷ��CPU���������ö�����ƣ�����2�㹻
	std::vector<IOService> _ioServices;
	std::vector<WorkPtr> _works;//����IOService
	std::vector<std::thread> _threads;//�ж��������ľ����׶��ٸ��߳�
	std::size_t  _nextIOService;//������������һ��ioService���� ��ѯ��ʽ
};

