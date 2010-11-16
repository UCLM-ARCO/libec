// -*- coding:utf-8; mode:c++ -*-

#include <fstream>
#include <vector>
#include <map>
#include <stdexcept>

namespace ec {
  
  class ConfigParser {
  public:

    class NoOptionError: public std::runtime_error {
    public:
      NoOptionError(const std::string& msg = ""):
	std::runtime_error(msg) { };
    };

    class NoSectionError: public std::runtime_error {
    public:
      NoSectionError(const std::string& msg = ""):
	std::runtime_error(msg) { };
    };
    
    void readfp(std::ifstream& fp);
    std::vector<std::string> sections() const;
    std::vector<std::string> options(const std::string& section) const;
    std::vector<std::string> get(const std::string& section, const std::string& option) const;

  private:
    typedef std::map<std::string, std::map<std::string, std::vector<std::string> > > Config;
    Config _content;
  };
  
}
