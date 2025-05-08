#pragma once
#include "const.h"
#include "mysqlDao.h"
class mysqlMgr :public Singleton<mysqlMgr>
{
	friend class Singleton<mysqlMgr>;
public:
	~mysqlMgr();
	int RegUser(const std::string& name, const std::string& email, const std::string& pwd);
	bool CheckEmail(const std::string& name, const std::string& email);
	bool UpdatePwd(const std::string& name, const std::string& pwd);
	bool CheckPwd(const std::string& name, const std::string& pwd, UserInfo& userInfo);
private:
	mysqlMgr();
	mysqlDao  _dao;
};

