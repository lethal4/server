#include "mysqlMgr.h"
mysqlMgr::~mysqlMgr() {
	std::cout << "mysqlMgr: Destructor called." << std::endl;
}

int mysqlMgr::RegUser(const std::string& name, const std::string& email, const std::string& pwd)
{
	try {
		int result = _dao.RegUser(name, email, pwd);
		if (result == 0) {
			std::cout << "mysqlMgr: User registered successfully." << std::endl;
		}
		else {
			std::cerr << "mysqlMgr: User registration failed with code: " << result << std::endl;
		}
		return result;
	}
	catch (const std::exception& e) {
		std::cerr << "mysqlMgr: Exception during RegUser: " << e.what() << std::endl;
		return -1;
	}
}
bool mysqlMgr::CheckEmail(const std::string& name, const std::string& email) {
	return _dao.CheckEmail(name, email);
}

bool mysqlMgr::UpdatePwd(const std::string& name, const std::string& pwd) {
	return _dao.UpdatePwd(name, pwd);
}

bool mysqlMgr::CheckPwd(const std::string& name, const std::string& pwd, UserInfo& userInfo) {
	return _dao.CheckPwd(name, pwd, userInfo);
}

mysqlMgr::mysqlMgr() {
}