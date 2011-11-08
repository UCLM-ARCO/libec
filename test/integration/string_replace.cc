// -*- mode:c++ -*-
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <assert.h>

#include "logger.h"
#include "string.h"

using namespace std;

int
main(int argc, char* argv[]) {

  if (argc != 4) {
    cout << "wrong usage" << endl;
    return 1;
  }

  cout << argv[1] << endl;
  cout << ec::string::replace(argv[1], argv[2], argv[3]) << endl;
  return 0;
}
