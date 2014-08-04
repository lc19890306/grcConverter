#include <iostream>
#include "grc_options.h"

options::options() {
  std::cout<<"options is initialized"<<endl;
}

options::~options() {
}

const object * options::theObject = object::register<options>("options");
