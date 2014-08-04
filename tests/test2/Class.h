/*
 * C++对象动态创建(Dynamic Create)实现
 * 实现基本的根据类名创建类实例，并且可以判断一个实例对某个类是否可赋值（assignment-compatible）
 *  Created on: 2012-5-11
 *      Author: torytin
 */

#ifndef CLASS_H_
#define CLASS_H_
#include <map>
#include <string>
using namespace std;
//动态创建声明宏定义
#define DYNAMIC_CREATE_DECLARE()		\
  public:					\
  static const Class*const theClass;		\
  virtual const Class *getClass();
//动态创建实现宏定义,baseclass是要声明的类，superclass是该类的父类
#define DYNAMIC_CREATE_IMPLEMENT(baseclass,superclass)			\
  const Class *baseclass::getClass(){					\
    return baseclass::theClass;						\
  }									\
  const Class *const baseclass::theClass = Class::Register<baseclass,superclass>(#baseclass);
/**
 * Object类，需要动态生成的类都必须继承该类
 * 目前该类无任何功能，只是一个标记
 * @author torytin
 *
 */
class Class;
class Object {
  //动态创建声明
  DYNAMIC_CREATE_DECLARE();
 public:
  virtual ~Object();
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
  static map<string, const Class*> classMap;
  //类的名称
  string name;
  //该类的父类指针
  const Class * superclass;
  //Class类不允许外部初始化
  Class() {
  }
 public:
  /***
   * Class类注册函数，该注册函数是template函数。
   * 用户需要提供T的具体类型和该类的父类类型，比如注册继承Object类的Example类的Class：
   * Class::Register<Example,Object>("Example");
   * 参数：
   * 		T:注册类的类型
   * 		P:注册类的父类类型
   * 		className:注册的类名标识符
   */
  template<class T,class P> static const Class * Register(string className) {
    //还没有注册该类，则注册
    if (classMap.count(className) == 0) {
      Class *cls = new Class();
      cls->factory = &ObjectFactory<T>::create; //函数指针赋值，根据T的类型赋值相应的创建函数
      cls->name = className; //类名的唯一标识符
      cls->superclass=P::theClass;
      classMap[className] = cls; //在这里注册该class类

    }
    return classMap[className];
  }
  ;
  //根据类的名字获得类对应的Class
  static const Class *forName(string className);
  //生成类的实例
  Object *newInstance() const;
  //获得类名
  string getName() const;
  //获得父类信息
  const Class *getSuperclass() const;
  //判断传入的对象对当前类是否可赋值（assignment-compatible）
  bool isInstance(Object *obj) const;
  virtual ~Class();
};
#endif /* CLASS_H_ */
