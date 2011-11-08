// -*- mode: c++; coding: utf-8 -*-

#include <vector>
#include <string>
#include "os.h"

using namespace std;

int
main(int argc, char* argv[]) {

  string name = argv[1];

  vector<string> paths;
  for (int i=2; i<argc; i++) {
    paths.push_back(argv[i]);
  }

  cout << ec::os::path::resolve_file(name, paths) << endl;

  return 0;
}
