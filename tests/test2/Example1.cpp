/*
 * Example1.cpp
 *
 *  Created on: 2012-5-13
 *      Author: torytin
 */
#include <iostream>
#include "Example1.h"

Example1::Example1() {
  std::cout<<"Example1 is initialized"<<endl;

}
Example1::~Example1() {
  // TODO Auto-generated destructor stub
}
DYNAMIC_CREATE_IMPLEMENT(Example1,Object)
