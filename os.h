// -*- mode:c++ -*-

#ifndef __EASY_OS_H__
#define __EASY_OS_H__

#include "./string.h"
#include <string>

namespace ec {

  namespace os {

    extern const std::string sep;

    namespace path {

      bool exists(const std::string& fpath);

      std::string join(const std::vector<std::string>& fields);

      /* Return 'fname' path if it exists in any 'paths' directory. */
      std::string resolve_file(const std::string& fname,
			      const std::vector<std::string>& paths);
    };
  };
};

#endif
