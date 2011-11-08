// -*- mode:c++ -*-

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <iostream>
#include <assert.h>

#include <string>


#include "./string.h"

const std::string ec::string::hexdigits = "0123456789abcdefABCDEF";
const std::string ec::string::whitespace = " \t\n\r\v\f";

bool
ec::string::endswith(const std::string& str, const std::string& suffix) {

  return str.compare(str.size()-suffix.size(), suffix.size(), suffix) == 0;
}


std::string
ec::string::join(const std::string& str, const std::vector<std::string>& fields) {

  if (fields.size() == 0) return "";

  std::string retval;
  unsigned int i;
  for(i = 0; i < fields.size() - 1; ++i)
    retval += fields[i] + str;

  retval += fields[i];
  return retval;
}


std::string
ec::string::lower(const std::string& str) {
  std::string retval(str.size(), ' ');
  transform(str.begin(), str.end(), retval.begin(), ::tolower);
  return retval;
}


std::vector<std::string>
ec::string::split(const std::string& str,
		  const std::string& sep, // = whitespace
		  int maxsplit /* = -1 */ ) {

  // python documentation states maxsplit default value is 0, but in the code value is -1
  // python doesn't allow to pass maxsplit argument with default separator (split function?)

  std::vector<std::string> retval;
  size_t i, k = 0;

  int sep_size = sep.size();

  if (sep == whitespace)
	while ((i = str.find_first_of(sep, k)) != std::string::npos) {
	  if (k == 0 || i != k)
		retval.push_back(str.substr(k,i-k));

	  k = i + 1;
	}

  else
	while ((i = str.find(sep, k)) != std::string::npos) {
	  if (--maxsplit == -1) break;

	  retval.push_back(str.substr(k,i-k));
	  k = i + sep_size;
	}

  retval.push_back(str.substr(k));
  return retval;
}


std::string
ec::string::replace(const std::string& str,
		    const std::string& old, const std::string& new_,
		    std::string::size_type count) {

  std::string retval(str);
  std::string::size_type i = 0, pos = 0;

  while ((pos = retval.find(old, pos)) != std::string::npos) {
    //std::cout << " pos:" << pos << " : " << retval << std::endl;
    retval.replace(pos, old.size(), new_);
    pos += new_.size();
    if (++i == count) break;
  }

  return retval;
}



bool
ec::string::startswith(const std::string& str, const std::string& prefix) {
  return str.compare(0, prefix.size(), prefix) == 0;
}


std::string
ec::string::lstrip(const std::string& str, const std::string& remove) {

  std::string retval=str;

  size_t first = retval.find_first_not_of(remove);
  if (first != std::string::npos) retval.erase(0, first);
  return retval;
}

std::string
ec::string::rstrip(const std::string& str, const std::string& remove) {

  std::string retval=str;

  size_t last = retval.find_last_not_of(remove);
  if (last != std::string::npos) retval.erase(last+1);
  return retval;
}

std::string
ec::string::strip(const std::string& str, const std::string& remove) {
  return rstrip(lstrip(str, remove), remove);
}

// python: x.__contains__(y) <==> y in x
bool
ec::string::contains(const std::string& str, const std::string& substr) {
  return (str.find(substr) != std::string::npos);
}

bool
ec::string::isspace(const std::string& str) {
  if (str.size() == 0) return false;

  return (str.find_first_not_of(ec::string::whitespace) == std::string::npos);
}

std::string
ec::string::upper(const std::string& str) {
  std::string retval(str.size(), ' ');
  transform(str.begin(), str.end(), retval.begin(), ::toupper);
  return retval;
}



std::string
ec::string::itoa(int n) {
	std::stringstream s;
	s << n;
	return s.str();
}

/***********************
   OSTREAM INSERTERS
************************/

std::ostream&
std::operator<<(ostream& os, const std::vector<std::string>& p) {
  std::vector<std::string> aux;
  for (std::vector<std::string>::const_iterator it = p.begin(); it != p.end(); ++it) {
    aux.push_back("\"" + *it + "\"");
  }

  os << "[" << ec::string::join(", ", aux) << "]";
  return os;
}

std::ostream&
std::operator<<(ostream& os, const std::vector<int>& p) {
	std::vector<string> aux;
	for (std::vector<int>::const_iterator it = p.begin(); it != p.end(); ++it) {
		aux.push_back(ec::string::itoa(*it));
	}

	os << "[" << ec::string::join(", ", aux) << "]";
	return os;
}


std::ostream&
std::operator<<(ostream& os, const std::pair<std::string,std::string>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}


