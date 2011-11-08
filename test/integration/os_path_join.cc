// -*- mode:c++ -*-

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <assert.h>

//#include "logger.h"
#include "string.h"
#include "os.h"

using namespace std;

int
main(int argc, char* argv[]) {

  vector<string> a1;

  for (int i=1; i<argc; i++) {
    a1.push_back(argv[i]);
  }

  cout << ec::os::path::join(a1)  << endl;

  return 0;
}
