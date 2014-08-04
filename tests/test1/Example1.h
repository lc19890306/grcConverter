/*
 * Example1.h
 *
 *  Created on: 2012-5-13
 *      Author: torytin
 */

#ifndef EXAMPLE1_H_
#define EXAMPLE1_H_

#include "Class.h"
class Example1: public Object {
 public:
  int a1;
  static const Class * theClass;
  Example1();
  virtual ~Example1();
  void print() {
    std::cout << "Example1 printing...\n";
  }
};

#endif /* EXAMPLE1_H_ */
