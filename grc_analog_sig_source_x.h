#ifndef __H_GRC_ANALOG_SIG_SOURCE_X_
#define __H_GRC_ANALOG_SIG_SOURCE_X_

#include "grc_block.h"

class analog_sig_source_x: public block {
 public:
  static const object *theObject;
  analog_sig_source_x();
  virtual ~analog_sig_source_x();
  cppPair assembleStmt(blockInfo bi);

 private:
  string id;
  string _enabled;
  string type;
  string samp_rate;
  string waveform;
  string freq;
  string amp;
  string offset;
  string affinity;
  string minoutbuf;
  string _coordinate;
  string _rotation;
};

#endif // __H_GRC_ANALOG_SIG_SOURCE_X_
