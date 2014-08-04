#ifndef __H_GRC_OPTIONS_
#define __H_GRC_OPTIONS_

#include "grc_block.h"

class options: public block {
 public:
  static const object *theObject;
  options();
  virtual ~options();
  cppPair assembleStmt(blockInfo bi);

 private:
  string id;
  string _enabled;
  string title;
  string author;
  string description;
  string window_size;
  string generate_options;
  string category;
  string run_options;
  string run;
  string max_nouts;
  string realtime_scheduling;
  string _coordinate;
  string _rotation;
};

#endif // __H_GRC_OPTIONS_
