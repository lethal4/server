#include "ConfigManager.h"
ConfigManager::ConfigManager() {
	//�ò���C++14������C++17���汾������
	boost::filesystem::path current_path = boost::filesystem::current_path();
	//��ȡ�����µ�·��
	boost::filesystem::path config_path = current_path / "config.ini";
	//ƴ�ӣ�������/��Ϊ����
	std::cout << "Config path : " << config_path << std::endl;

	boost::property_tree::ptree pt;
	//��������ʽȥ��ȡ
	boost::property_tree::read_ini(config_path.string(), pt);

	for (const auto& section_pair : pt) {
		//gateserver ��varifyserver
		const std::string& section_name = section_pair.first;
		const boost::property_tree::ptree& section_tree = section_pair.second;
		std::map<std::string, std::string> section_config;
		for (const auto& key_value_pair : section_tree) {
			const std::string& key = key_value_pair.first;
			const std::string& value = key_value_pair.second.get_value<std::string>();
			//��value�е�treeת��string����
			section_config[key] = value;
		}

		SectionInfo sectionInfo;
		sectionInfo._section_datas = section_config;
		_config_map[section_name] = sectionInfo;

	}

	// ������е�section��key-value��  
	for (const auto& section_entry : _config_map) {
		const std::string& section_name = section_entry.first;
		SectionInfo section_config = section_entry.second;
		std::cout << "[" << section_name << "]" << std::endl;
		for (const auto& key_value_pair : section_config._section_datas) {
			std::cout << key_value_pair.first << "=" << key_value_pair.second << std::endl;
		}
	}
}