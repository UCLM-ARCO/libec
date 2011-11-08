// -*- coding:utf-8; mode:c++ -*-

#include <assert.h>
#include <string>

#include "ConfigParser.h"
#include "string.h"

void
ec::ConfigParser::readfp(std::ifstream& fp) {

  std::string line;
  std::string cursect;
  std::string curkey;
  std::map<std::string, std::vector<std::string> > attrs;

  while(std::getline(fp, line)) {

    // Blank lines
    if (ec::string::strip(line) == "")
      continue;

    if (ec::string::isspace(line))
      continue;

    // Comments
    if (ec::string::startswith(line, "#"))
      continue;

    // Ignore middle comments
    line = ec::string::split(line, "#")[0];

    // Line continuing...
    if (ec::string::startswith(line, " ") or ec::string::startswith(line, "\t")) {
		assert (curkey != "");
		attrs[curkey].push_back(ec::string::strip(line));
		continue;
    }

    // Start section
    if (ec::string::startswith(line, "[")) {
		line = ec::string::strip(line);

		if (cursect != "")
			_content[cursect] = attrs;

		cursect = ec::string::strip(line, "[]");

		attrs.clear();
		continue;
    }

    // A pair key = value
    curkey = ec::string::strip(ec::string::split(line, "=")[0]);
    attrs[curkey].push_back(ec::string::strip(ec::string::split(line, "=")[1]));
  }

  _content[cursect] = attrs;

}

std::vector<std::string>
ec::ConfigParser::sections() const {
  std::vector<std::string> retval;

  ec::ConfigParser::Config::const_iterator it;
  for ( it=_content.begin() ; it != _content.end(); it++)
    retval.push_back(it->first);

  return retval;
}

std::vector<std::string>
ec::ConfigParser::options(const std::string& section) const {

  Config::const_iterator it = _content.find(section);
  if (it == _content.end())
    throw ec::ConfigParser::NoSectionError("No section '" + section + "'");

  std::vector<std::string> retval;

  for (std::map<std::string, std::vector<std::string> >::const_iterator i = it->second.begin();
       i != it->second.end(); i++)
    retval.push_back(i->first);
  return retval;

}


std::vector<std::string>
ec::ConfigParser::get(const std::string& section, const std::string& option) const {

  Config::const_iterator i = _content.find(section);
  if (i == _content.end())
    throw ec::ConfigParser::NoSectionError("No section '" + section + "'");

  std::map<std::string, std::vector<std::string> >::const_iterator j;
  j = i->second.find(option);

  if (j == i->second.end())
    throw ec::ConfigParser::NoOptionError("No option '" + option \
					  + "' in section: '" + section + "'");
  return j->second;
}
