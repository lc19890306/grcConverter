/*
 * Class.cpp
 *
 *  Created on: 2012-5-11
 *      Author: torytin
 */

#include "Class.h"

map<string,const Class*> Class::classMap=map<string,const Class*>();

const Class *Class::forName(string className) {
  if (classMap.count(className) != 0) {
    return classMap[className];
  }
  return NULL;
}
Object *Class::newInstance() const {
  return factory();
}
string Class::getName() const{
  return name;
}
const Class *Class::getSuperclass() const{
  return superclass;
}
bool Class::isInstance(Object *obj) const{
  if(obj == NULL) return false;
  const Class *cls = obj->getClass();
  while(cls!=NULL){
    if(this == cls){
      return true;
    }else{
      cls = cls->getSuperclass();
    }
  };
  return false;
}
Class::~Class() {
}
Object::~Object(){
}
//动态创建实现
DYNAMIC_CREATE_IMPLEMENT(Object,Object)
