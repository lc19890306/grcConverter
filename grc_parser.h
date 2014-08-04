#ifndef __H_GRC_PARSER_
#define __H_GRC_PARSER_

#include <libxml/parser.h>
#include <iostream>
#include <vector>
#include "grc_structures.h"
#include "grc_strop.h"

using namespace std;

class grcParser {
 public:
  grcParser() {}
  ~grcParser() {}

  string parse(char *grcFile);
  void parseNode(xmlNodePtr &curNode, blockInfoPtr b = NULL, connectionInfoPtr c = NULL, paramInfoPtr p = NULL, unsigned level = 0);
  vBlock getBlocks() const;
  vConnection getConnections() const;

 private:
  vBlock blocks;
  vConnection connections;
};

#endif // __H_GRC_PARSER_
