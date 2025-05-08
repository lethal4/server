#include "statusGrpcClient.h"

GetChatServerRsp statusGrpcClient::GetChatServer(int uid) {
	ClientContext context;
	GetChatServerReq request;
	GetChatServerRsp reply;
	request.set_uid(uid);
	auto stub = pool_->getConnection();
	Status status = stub->GetChatServer(&context, request, &reply);
	Defer defer([&stub, this]() {
		pool_->returnConnection(std::move(stub));
		});
	if (status.ok()) {
		return reply;
	}
	else {
		reply.set_error(ErrorCodes::RPCFailed);
		return reply;
	}
}

statusGrpcClient::statusGrpcClient()
{
	auto& gCfgMgr = ConfigManager::Inst();
	std::string host = gCfgMgr["StatusServer"]["Host"];
	std::string port = gCfgMgr["StatusServer"]["Port"];
	pool_.reset(new StatusConPool(6, host, port));//连接池大小
}