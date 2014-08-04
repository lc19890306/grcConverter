#include "grc_main.h"

int main(int argc, char **argv) {
  char *grcFile = argv[1];
  grcParser p;
  string res = p.parse(grcFile);
  if (res == "Error") {
    return -1;
  }
  vBlock blocks = p.getBlocks();
  vConnection connections = p.getConnections();
  for (unsigned i = 0; i < blocks.size(); ++i) {
    std::cout << blocks[i].getKey() << std::endl;
    vParam params = blocks[i].getParams();
    for (unsigned j =0; j < params.size(); ++j) {
      std::cout << params[j].getKey() << " = " << params[j].getValue() << std::endl;
    }
    std::cout << "\n";
  }

  cppAssembler a(res);
  a.assemble(blocks, connections);
  
  return 0;
}
