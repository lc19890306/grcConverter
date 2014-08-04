#include <iostream>

using namespace std;

class Base {
public:
  Base() {
    cout << "Base constructor\n";
  }
  ~Base() {
    cout << "Base destructor\n";
  }
  virtual void print() {
    cout << "Base printing...\n";
  }
};

class Derived1: public Base {
public:
  Derived1() {
    cout << "Derived1 constructor\n";
  }
  ~Derived1() {
    cout << "Derived1 destructor\n";
  }
  void print() {
    cout << "Derived1 printing...\n";
  }
};

class Derived2: public Base {
public:
  Derived2() {
    cout << "Derived2 constructor\n";
  }
  ~Derived2() {
    cout << "Derived2 destructor\n";
  }
};

int main() {
  Base *obj1 = new Derived1();
  Base *obj2 = new Derived2();

  obj1->print();

  return 0;
}
