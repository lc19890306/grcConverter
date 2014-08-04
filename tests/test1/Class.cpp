/*
 * Class.cpp
 *
 *  Created on: 2012-5-11
 *      Author: torytin
 */

#include "Class.h"
map<string, Class*> Class::classMap=map<string, Class*>();
string Class::getName() const{
  return name;
}
Class *Class::forName(string className) {
  if (classMap.count(className) != 0) {
    return classMap[className];
  }
  return NULL;
}
Object *Class::newInstance() const {
  return factory();
}
Class::~Class() {
}
//注册Object类信息，在这里，我们把返回的Class类存放在theClass中，方便后续使用
const Class *const Object::theClass = Class::Register<Object>("Object");
