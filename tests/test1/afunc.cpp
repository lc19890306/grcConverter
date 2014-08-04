/*
 * Example.cpp
 *
 *  Created on: 2012-5-11
 *      Author: torytin
 */
#include <iostream>
#include "afunc.h"

afunc::afunc() {
  std::cout<<"afunc is initialized"<<endl;
}

afunc::~afunc() {
}


//注册afunc类信息，在这里，我们把返回的Class类存放在theClass中，方便后续使用
const Class * afunc::theClass = Class::Register<afunc>("afunc");
