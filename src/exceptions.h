// -*- mode:c++ -*-

#ifndef __EASY_EXCEPTIONS_H__
#define __EASY_EXCEPTIONS_H__

#include <string>
#include <stdexcept>

namespace ec {

  class ValueError : public std::runtime_error {
  public:
  ValueError(const std::string& msg="") : std::runtime_error(msg) {}
  };

  class IOError : public std::runtime_error {
  public:
  IOError(const std::string& msg="") : std::runtime_error(msg) {}
  };

};


#endif
