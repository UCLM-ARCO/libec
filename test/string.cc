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


void
f(std::string x) {
  cout << x.size() << endl;
}


int
main() {

  std::string a("hola");
  f(a);
  return 0;
}
