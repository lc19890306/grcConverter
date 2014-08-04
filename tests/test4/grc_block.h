#ifndef __H_GRC_BLOCK_
#define __H_GRC_BLOCK_

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "grc_structures.h"

using namespace std;

class object;
class block {
 public:
  static const object *const theObject;

  //  virtual string assembleStmt(blockInfo bi) {}
};

template<class T>
class blockFactory {
 public:
  static block *create() {
    return new T();
  }
};

class object {
 public:
  template<class T> static object *register(string objectName) {
    if (objectMap.count(objectName) == 0) {
      object *obj = new object();
      obj->factory = &blockFactory<T>::create;
      obj->name = objectName;
      objectMap[objectName] = obj;
    }
    return objectMap[objectName];
  }

  static object *forName(string objectName);
  block *newInstance() const;
  string getName() const;
  virtual ~object();

 private:
  object() {}
  block *(*factory)(void);
  static map<string, object *> objectMap;
  string name;
};

#endif // __H_GRC_BLOCK_
