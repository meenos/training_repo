#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include <string>
#include <map>
#include <vector>

class Config
{
public:
	Config();
	Config(const std::map<std::string, std::string> &config);
	
	static Config *load(const std::string &path);
	bool save(const std::string &path);
	
	void beginGroup(const std::string &group);
	void endGroup();
	void clearGroup();
	
	bool containsKey(const std::string &key) const;
	
	bool boolValue(const std::string &key) const;
	int intValue(const std::string &key) const;
	double doubleValue(const std::string &key) const;
	std::string stringValue(const std::string &key) const;
	
	void setValue(const std::string &key, const bool &value);
	void setValue(const std::string &key, const int &value);
	void setValue(const std::string &key, const double &value);
	void setValue(const std::string &key, const char *value);
	void setValue(const std::string &key, const std::string &value);
	
private:
	std::string safeKey(std::string key) const;
	std::string group() const;
	
	std::map<std::string, std::string> m_config;
	std::vector<std::string> m_groups;
};

#endif