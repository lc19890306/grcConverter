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


//注册Example类信息，在这里，我们把返回的Class类存放在theClass中，方便后续使用
const Class * Example::theClass = Class::Register<Example>("Example");
