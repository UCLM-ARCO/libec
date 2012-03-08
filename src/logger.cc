// -*- mode: c++; coding: utf-8 -*-

#include "logger.h"

#include <iostream>
#include <fstream>


ec::Logger ec::Logger::root;

std::ostream& ec::debug(void)    { return ec::Logger::root(ec::Logger::DEBUG); }
std::ostream& ec::info(void)     { return ec::Logger::root(ec::Logger::INFO); }
std::ostream& ec::warn(void)     { return ec::Logger::root(ec::Logger::WARNING); }
std::ostream& ec::error(void)    { return ec::Logger::root(ec::Logger::ERROR); }
std::ostream& ec::fatal(void) { return ec::Logger::root(ec::Logger::FATAL); }

std::ostream&
ec::Logger::operator()(ec::Logger::Level msg_level) {
  const char* level_names[] = {"*", "DEBUG", "INFO", "WARNING", "ERROR", "FATAL"};

  if (msg_level < level) return ec::Logger::get_null();

  std::cout << "[" << level_names[msg_level] << "] ";
  if (not name.empty()) 
    std::cout << name << " ";
  return std::cout;
}

std::ofstream&
ec::Logger::get_null(void) {
  return ((_dev_null) ? *_dev_null : *(_dev_null = new std::ofstream("/dev/null")));
}
