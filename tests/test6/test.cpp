#include <map>
#include <iostream>

using namespace std;

class c {
public:
  static map<string, int> m;
};

class c1 {
public:
static 

//map<string, int> c::m = map<string, int>();

int main() {
  cout << c::m.size() << endl;
  cout << c::m.count("str") << endl;
  c::m.insert(pair<string, int>("str", 1));
  cout << c::m.size() << endl;
  return 0;
}
