// -*- mode:c++ -*-
#include "string.h"

using namespace std;

int
main(int argc, char* argv []) {

    if (argc != 2) return 1;

    cout << argv[1] << endl;
    cout << ec::string::upper(argv[1]) << endl;

    return 0;
}
