// -*- mode:c++ -*-
#include <vector>
#include <string>

#include "string.h"

using namespace std;

int
main(int argc, char* argv []) {

  if (argc < 2) {
    cerr << "wrong usage";
    return 1;
  }

  vector<string>* fields;

  if (argc == 4)
    fields = new vector<string>(ec::string::split(argv[1], argv[2], atoi(argv[3])));
  else if (argc == 3)
    fields = new vector<string>(ec::string::split(argv[1], argv[2]));
  else
	fields = new vector<string>(ec::string::split(argv[1]));

  cout << argv[1] << endl;
  cout << *fields << endl;

  delete fields;
  return 0;
}
