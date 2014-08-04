/*
 * SubExample.cpp
 *该类继承Example
 *  Created on: 2012-5-14
 *      Author: Torytin
 */
#include <iostream>
#include "SubExample.h"

SubExample::SubExample() {
  cout<<"SubExample is initialized"<<endl;
}
SubExample::~SubExample() {
  // TODO Auto-generated destructor stub
}
DYNAMIC_CREATE_IMPLEMENT(SubExample,Example)
