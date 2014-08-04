#ifndef __H_GRC_ASSEMBLER_
#define __H_GRC_ASSEMBLER_

#include "grc_headers.h"
#include "grc_structures.h"
#include "grc_block.h"

class cppAssembler {
 public:
  cppAssembler() {}
 cppAssembler(string filename): filename(filename) {}
  ~cppAssembler() {}

  void assemble(vBlock blocks, vConnection connections);

 private:
  string filename;
};

#endif // __H_GRC_ASSEMBLER_
