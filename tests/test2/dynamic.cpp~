//============================================================================
// Name        : dynamic.cpp
// Author      : torytin
// Version     :
// Copyright   :
// Description :Object dynamic create in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Example.h"
#include "Example1.h"
#include "SubExample.h"
using namespace std;

void testEqual(const Class *cls){
  cout<<"==========test Class equal function start========"<<endl;
  if(cls==Example::theClass){
    cout<<"it's a Example Class,instance it"<<endl;
    cls->newInstance();
  }else{
    cout<<"it's not a Example Class,not instance"<<endl;
  }
  cout<<"==========test Class equal function end========"<<endl;
}
void testAssignable(Object *obj){
  cout<<"==========test assignable function start========"<<endl;
  cout<<"the input Class is:"<<obj->getClass()->getName()<<endl;
  cout<<"is SubExample?:"<<SubExample::theClass->isInstance(obj)<<endl;
  cout<<"is Example?:"<<Example::theClass->isInstance(obj)<<endl;
  cout<<"is Object?:"<<Object::theClass->isInstance(obj)<<endl;
  cout<<"is Example1?:"<<Example1::theClass->isInstance(obj)<<endl;
  cout<<"==========test assignable function end========"<<endl;
}
int main() {
  testEqual(Class::forName("Example"));
  testEqual(Class::forName("Example1"));
  testAssignable(Class::forName("SubExample")->newInstance());
  testAssignable(Class::forName("Example1")->newInstance());
  return 0;
}
