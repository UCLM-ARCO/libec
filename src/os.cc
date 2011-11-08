// -*- mode:c++ -*-

#include "os.h"
#include "string.h"
#include "logger.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>

const std::string ec::os::sep = "/";

bool
ec::os::path::exists(const std::string& fpath) {
  struct stat values;
  return (stat(fpath.c_str(), &values) == 0);
}

std::string
ec::os::path::join(const std::vector<std::string>& fields) {

  if (fields.size() == 0) return "";

  std::string retval;
  std::vector<std::string> aux(fields.begin(), fields.end());

  //std::cout << aux << std::endl;

  unsigned int i;
  for(i = 0; i < aux.size() - 1; ++i) {
    aux[i] = ec::string::strip(aux[i], ec::os::sep);
    //    std::cout << i << ":" << aux[i] << ":" << retval << std::endl;
  }

  retval = ec::string::join(ec::os::sep, aux);
  //  std::cout << retval << std::endl;

  if (fields[0][0] == '/')
    retval = '/' + retval;

  //std::cout << retval << std::endl;

  return retval;
}


std::string
ec::os::path::resolve_file(const std::string& fname,
			  const std::vector<std::string>& paths) {

  ec::info() << "os::path::resolveFile(): Searching '" << fname << "' in " << paths << std::endl;

  for(std::vector<std::string>::const_iterator it = paths.begin();
      it != paths.end(); ++it) {

    std::vector<std::string> fields;
    fields.push_back(ec::string::strip(*it));
    fields.push_back(ec::string::strip(fname));

    std::string abspath = ec::os::path::join(fields);
    if (ec::os::path::exists(abspath)) return abspath;
  }

  return "";
}
