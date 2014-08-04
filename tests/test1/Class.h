/*
 * C++对象动态创建(Dynamic Create)简单实现
 *使用方法：对每一个需要动态创建的类，继承自Object类，并调用Class::Register<Class>(className)注册一下即可
 *  Created on: 2012-5-11
 *      Author: torytin
 */

#ifndef CLASS_H_
#define CLASS_H_
#include <map>
#include <string>
#include <iostream>
using namespace std;
/**
 * Object类，需要动态生成的类都必须继承该类
 * 目前该类无任何功能，只是一个标记
 * @author torytin
 */
class Class;
class Object {
 public:
  //用来保存创建的Class类
  static const Class *const theClass;

  virtual void print() {
    std::cout << "Object printing...\n";
  }
};
/**
 * 对象工厂模板类，该类用来生成具体的对象
 * @author torytin
 *
 */
template<class T> class ObjectFactory {
 public:
  static Object *create() {
    return new T();
  }
  ;
};
/**
 * Class类，用来存储类信息
 * 为了可以把具体的类型对用户隐藏，Class类没有设成模板类
 * 因为C++的模板类对象持有的时候必须指定具体的类名，如果设定为模板类
 * 使用的时候只能是Class<类名> *pClass，而不能是Class *pClass。
 * 用户还是需要知道具体类名，就失去了动态创建的意义，但为了达到动态创建的目的，
 * Class类的Register是一个template函数，具体的类型信息，需要用户在注册类的时候提供
 * @author torytin
 *
 */
class Class {
 private:
  //创建对象的函数指针定义
  Object *(*factory)(void);
  //用来存储当前注册的所有可动态创建的Class
  static map<string, Class*> classMap;
  //类的名称
  string name;
  //Class类不允许外部初始化
  Class() {
  }
 public:
  /***
   * Class类注册函数，该注册函数是template函数。
   * 用户需要提供T的具体类型和类的唯一标识符（一般为类名），比如生成Example类的Class：
   * Class::Register<Example>("Example");
   * 参数：
   * 		T:具体的类
   * 		className:注册的名字（一般为类名，也可以为任意字符）
   */
  template<class T> static Class * Register(string className) {
    if (classMap.count(className)==0) {
      Class *cls = new Class();
      cls->factory = &ObjectFactory<T>::create; //函数指针赋值，根据T的类型赋值相应的创建函数
      cls->name = className; //类名的唯一标识符
      classMap[className] = cls; //在这里注册该class类
    }
    return classMap[className];
  }
  ;
  //根据类的名字获得类对应的Class
  static Class *forName(string className);
  //生成类的实例
  Object *newInstance() const;
  //获得类名
  string getName() const;
  virtual ~Class();
};
#endif /* CLASS_H_ */
