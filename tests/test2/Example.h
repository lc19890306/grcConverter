/*
 * C++动态创建类示例
 * 对象必须继承Object类，并且必须有一个无参的构造函数
 *  Created on: 2012-5-11
 *      Author: torytin
 */

#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include "Class.h"
class Example: public Object{
  DYNAMIC_CREATE_DECLARE();
 public:
  Example();
  virtual ~Example();
};

#endif /* EXAMPLE_H_ */
