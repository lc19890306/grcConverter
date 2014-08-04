#include "grc_block.h"

map<string, object *> object::objectMap = map<string, object *>();

string object::getName() const {
  return name;
}

object *object::forName(string objectName) {
  if (objectMap.count(objectName) != 0) {
    return objectMap[objectName];
  }
  return NULL;
}

block *object::newInstance() const {
  return factory();
}

object::~object() {}

const object *const block::theObject = object::register<block>("block");
