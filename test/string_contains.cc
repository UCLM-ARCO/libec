// -*- mode:c++ -*-
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <assert.h>

#include "string.h"

using namespace std;

int
main(int argc, char* argv[]) {

  if (argc != 3) {
    cout << "wrong usage" << endl;
    return 1;
  }

  cout << ec::string::contains(argv[1], argv[2]) << endl;
  return 0;
}
