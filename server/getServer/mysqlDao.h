#pragma once
#include "const.h"
#include <thread>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

class sqlConnection {
public:
	sqlConnection(sql::Connection* con, int64_t lasttime) :_con(con), _last_oper_time(lasttime) {}
	int64_t _last_oper_time;
	std::unique_ptr <sql::Connection> _con;//sql连接，自动回收
};
class mySqlPool {
public:
	mySqlPool(const std::string& url, const std::string& user, const std::string& pass, const std::string& schema, int poolSize)
		: url_(url), user_(user), pass_(pass), schema_(schema), poolSize_(poolSize), b_stop_(false) {
		try {
			for (int i = 0; i < poolSize_; ++i) {
				sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
				std::unique_ptr<sql::Connection> con(driver->connect(url_, user_, pass_));
				con->setSchema(schema_);
				pool_.push(std::move(con));
			}
		}
		catch (sql::SQLException& e) {
			// 处理异常
			std::cout << "mysql pool init failed" << std::endl;
		}
	}

	std::unique_ptr<sql::Connection> getConnection() {
		std::unique_lock<std::mutex> lock(mutex_);
		cond_.wait(lock, [this] {
			if (b_stop_) {
				return true;
			}
			return !pool_.empty(); });
		if (b_stop_) {
			return nullptr;
		}
		std::unique_ptr<sql::Connection> con(std::move(pool_.front()));
		pool_.pop();
		return con;
	}

	void returnConnection(std::unique_ptr<sql::Connection> con) {
		std::unique_lock<std::mutex> lock(mutex_);
		if (b_stop_) {
			return;
		}
		pool_.push(std::move(con));
		cond_.notify_one();
	}

	void Close() {
		b_stop_ = true;
		cond_.notify_all();
	}

	~mySqlPool() {
		std::unique_lock<std::mutex> lock(mutex_);
		while (!pool_.empty()) {
			pool_.pop();
		}
	}

private:
	std::string url_;
	std::string user_;
	std::string pass_;
	std::string schema_;
	int poolSize_;
	std::queue<std::unique_ptr<sql::Connection>> pool_;
	std::mutex mutex_;
	std::condition_variable cond_;
	std::atomic<bool> b_stop_;
};
struct UserInfo {
	std::string name;
	std::string pwd;
	int uid;
	std::string email;
};
class mysqlDao
{
public:
	mysqlDao();
	~mysqlDao();
	int RegUser(const std::string& name, const std::string& email, const std::string& pwd);
	bool CheckEmail(const std::string& name, const std::string& email);
	bool UpdatePwd(const std::string& name, const std::string& pwd);

	bool CheckPwd(const std::string& name, const std::string& pwd, UserInfo& userInfo);
	void TestConnection() {
		try {
			// 获取连接
			auto conn = pool_->getConnection();
			if (!conn) {
				std::cerr << "Failed to get a database connection from the pool!" << std::endl;
				return;
			}

			// 执行简单的测试查询
			std::unique_ptr<sql::Statement> stmt(conn->createStatement());
			std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT 1"));

			if (res->next()) {
				std::cout << "MySQL connection test succeeded: " << res->getInt(1) << std::endl;
			}
			else {
				std::cerr << "Failed to execute test query on MySQL!" << std::endl;
			}

			// 归还连接
			pool_->returnConnection(std::move(conn));
		}
		catch (sql::SQLException& e) {
			std::cerr << "MySQL connection test failed!" << std::endl;
			std::cerr << "Error: " << e.what() << std::endl;
			std::cerr << "SQLState: " << e.getSQLState() << std::endl;
			std::cerr << "ErrorCode: " << e.getErrorCode() << std::endl;
		}
	}
private:
	std::unique_ptr<mySqlPool> pool_;
};

