/*
 * Example.cpp
 *
 *  Created on: 2012-5-11
 *      Author: torytin
 */
#include <iostream>
#include "Example.h"

Example::Example() {
  std::cout<<"Example is initialized"<<endl;
}
Example::~Example() {
}
DYNAMIC_CREATE_IMPLEMENT(Example,Object)
