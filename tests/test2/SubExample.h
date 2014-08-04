/*
 * SubExample.h
 * 该类继承Example
 *  Created on: 2012-5-14
 *      Author: Torytin
 */

#ifndef SUBEXAMPLE_H_
#define SUBEXAMPLE_H_

#include "Example.h"

class SubExample: public Example {
  DYNAMIC_CREATE_DECLARE();
 public:
  SubExample();
  virtual ~SubExample();
};

#endif /* SUBEXAMPLE_H_ */
