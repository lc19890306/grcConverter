/*
 * C++动态创建类示例
 * 对象必须继承Object类，并且必须有一个无参的构造函数
 * 定义对象后需要调用Class::Register函数注册当前类，可以把生成的Class保存在static变量中供后续使用
 *  Created on: 2012-5-11
 *      Author: torytin
 */

#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include "Class.h"
class Example: public Object{
 public:
  int a;
  //用来保存创建的Class类，这里保存只是为了方便使用，不是强制要求
  static const Class * theClass;
  Example();
  virtual ~Example();
  void print() {
    std::cout << "Example printing...\n";
  }
};

#endif /* EXAMPLE_H_ */
