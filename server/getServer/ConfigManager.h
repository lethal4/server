#pragma once
#include "const.h"
struct SectionInfo {
	//管理config.ini
	SectionInfo() {};
	~SectionInfo() { _section_datas.clear(); };

	//拷贝构造
	SectionInfo(const SectionInfo& src) {
		_section_datas = src._section_datas;
	}
	SectionInfo& operator = (const SectionInfo& src) {
		if (&src == this) {
			return *this;
			//不允许自己拷贝构造自己
			// //重载 = 号
		}

		this->_section_datas = src._section_datas;
		return *this;
	}
	std::map<std::string, std::string> _section_datas;
	std::string operator[](const std::string& key) {
		if (_section_datas.find(key) == _section_datas.end()) {
			return "";
		}
		return _section_datas[key];
	}
};
class ConfigManager
{
public:
	~ConfigManager() {
		_config_map.clear();
	}
	SectionInfo operator[](const std::string& section) {
		if (_config_map.find(section) == _config_map.end()) {
			return SectionInfo();
			//没找到则返回空的section
		}

		return _config_map[section];
	}//希望sectioninfo也能下标访问


	static ConfigManager& Inst() {
		static ConfigManager cfg_mgr;//仅第一次初始化，后续所有公用这一个（C++11之后）
		return cfg_mgr;//局部静态变量生命周期和进程同步
	}
	//拷贝构造
	ConfigManager(const ConfigManager& src) {
		_config_map = src._config_map;

	}

	//拷贝赋值 重载 = 号
	ConfigManager& operator = (const ConfigManager& src) {
		if (&src == this) {
			return *this;
		}
		_config_map = src._config_map;
	}
private:
	std::map<std::string, SectionInfo> _config_map;
	ConfigManager();
};

