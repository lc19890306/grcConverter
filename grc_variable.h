#ifndef __H_GRC_VARIABLE_
#define __H_GRC_VARIABLE_

#include "grc_block.h"

class variable: public block {
 public:
  static const object *theObject;
  variable();
  virtual ~variable();
  cppPair assembleStmt(blockInfo bi);

 private:
  string id;
  string _enabled;
  string value;
  string _coordinate;
  string _rotation;
};

#endif // __H_GRC_VARIABLE_
