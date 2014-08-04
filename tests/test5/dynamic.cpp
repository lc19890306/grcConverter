#include <iostream>
#include "grc_options.h"

using namespace std;

int main() {
  object::forName("options")->newInstance()->print();

  return 0;
}
