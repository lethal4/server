#include "VerifyGrpcClient.h"
#include "ConfigManager.h"

VerifyGrpcClient::VerifyGrpcClient() {
	auto& gCfgMgr = ConfigManager::Inst();
	std::string host = gCfgMgr["VarifyServer"]["Host"];
	std::string port = gCfgMgr["VarifyServer"]["Port"];
	pool_.reset(new RPConPool(5, host, port));//≥ı ºªØ¡¥Ω”
}