#include "grc_assembler.h"

using namespace std;

void cppAssembler::assemble(vBlock blocks, vConnection connections) {
  int i, size = blocks.size();
  cppFile outputFile(filename);
  outputFile.push_back("");
  outputFile.push_back("int main() {");

  for (i = 0; i < size; ++i) {
    blockInfo bi = blocks[i];
    string blockName = bi.getKey();
    block *blk = object::forName(blockName)->newInstance();
    outputFile.push_back(blk->assembleStmt(bi));
  }

  size = connections.size();
  for (i = 0; i < size; ++i) {
    connectionInfo ci = connections[i];
    string stmt = "  tb->";
    stmt += ci.createStmt();
    outputFile.push_back(stmt);
  }

  outputFile.push_back("  tb->run();");

  outputFile.push_back("");
  outputFile.push_back("  return 0;");
  outputFile.push_back("}");

  outputFile.print();
}
