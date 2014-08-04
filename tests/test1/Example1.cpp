/*
 * Example1.cpp
 *
 *  Created on: 2012-5-13
 *      Author: torytin
 */
#include <iostream>
#include "Example1.h"

Example1::Example1() {
  std::cout<<"Example1 is initialized\n";

}

Example1::~Example1() {
  // TODO Auto-generated destructor stub
}

//注册Example1类
const Class * Example1::theClass = Class::Register<Example1>("Example1");
