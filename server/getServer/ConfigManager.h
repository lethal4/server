#pragma once
#include "const.h"
struct SectionInfo {
	//����config.ini
	SectionInfo() {};
	~SectionInfo() { _section_datas.clear(); };

	//��������
	SectionInfo(const SectionInfo& src) {
		_section_datas = src._section_datas;
	}
	SectionInfo& operator = (const SectionInfo& src) {
		if (&src == this) {
			return *this;
			//�������Լ����������Լ�
			// //���� = ��
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
			//û�ҵ��򷵻ؿյ�section
		}

		return _config_map[section];
	}//ϣ��sectioninfoҲ���±����


	static ConfigManager& Inst() {
		static ConfigManager cfg_mgr;//����һ�γ�ʼ�����������й�����һ����C++11֮��
		return cfg_mgr;//�ֲ���̬�����������ںͽ���ͬ��
	}
	//��������
	ConfigManager(const ConfigManager& src) {
		_config_map = src._config_map;

	}

	//������ֵ ���� = ��
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

