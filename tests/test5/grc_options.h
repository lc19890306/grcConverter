#ifndef __H_GRC_OPTIONS_
#define __H_GRC_OPTIONS_

#include "grc_block.h"

class options: public block {
 public:
  static const object *theObject;
  options();
  virtual ~options();
  void print() {
    std::cout << "options printing...\n";
  }
};

#endif // __H_GRC_OPTIONS_
