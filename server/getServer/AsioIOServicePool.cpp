#include "AsioIOServicePool.h"
#include <iostream>
using namespace std;
AsioIOServicePool::AsioIOServicePool(std::size_t size) :_ioServices(size),
_works(size), _nextIOService(0) {//��֧�ֿ����������Ҫ���ڳ�ʼ���б���в���
	for (std::size_t i = 0; i < size; ++i) {
		_works[i] = std::unique_ptr<Work>(new Work(_ioServices[i]));//����ָ�뽻��unique_ptr����󴫵ݸ�work
	}

	//�������ioservice����������̣߳�ÿ���߳��ڲ�����ioservice
	for (std::size_t i = 0; i < _ioServices.size(); ++i) {
		_threads.emplace_back([this, i]() {//��ioServices����work����֤ioService�����˳�
			_ioServices[i].run();//�÷������� 
			});
	}
}

AsioIOServicePool::~AsioIOServicePool() {
	Stop();//�Ҵ�������Դ�����Լ�����
	std::cout << "AsioIOServicePool destruct" << endl;
}

boost::asio::io_context& AsioIOServicePool::GetIOService() {
	auto& service = _ioServices[_nextIOService++];
	if (_nextIOService == _ioServices.size()) {
		_nextIOService = 0;//�ֻ�ʹ���߳�
	}
	return service;
}

void AsioIOServicePool::Stop() {
	//��Ϊ����ִ��work.reset��������iocontext��run��״̬���˳�
	//��iocontext�Ѿ����˶���д�ļ����¼��󣬻���Ҫ�ֶ�stop�÷���
	for (auto& work : _works) {
		work->get_io_context().stop();//�ѷ�����ֹͣ
		work.reset();//��ɿ�ָ�룬����io_context,���run�ᶼ����
	}
	for (auto& t : _threads) {
		t.join();
	}
}