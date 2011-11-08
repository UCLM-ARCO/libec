// -*- mode:c++ -*-

#include <fstream>
#include <string>

#include "ConfigParser.h"
#include "string.h"

using namespace std;

int
main(int argc, char** argv) {
  ec::ConfigParser cp = ec::ConfigParser();
  ifstream in(argv[1]);
  cp.readfp(in);

  vector<string> secs = cp.sections();
  for (vector<string>::const_iterator i = secs.begin(); i != secs.end(); i++) {
    cout << "Section: '" << *i << "'" << endl;
    
    vector<string> opts = cp.options(*i);
    for (vector<string>::const_iterator j = opts.begin(); j!=opts.end(); j++) {
      cout << "   " << *j << " =";
      vector<string> values = cp.get(*i, *j);
      for (vector<string>::const_iterator k = values.begin(); k!=values.end(); k++) 
	cout << " " << *k;
      cout << endl;
    }
  }
}
  
