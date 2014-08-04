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
  DYNAMIC_CREATE_DECLARE();
 public:
  Example1();
  virtual ~Example1();
};

#endif /* EXAMPLE1_H_ */
