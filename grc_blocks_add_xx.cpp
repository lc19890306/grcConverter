#include "grc_blocks_add_xx.h"

blocks_add_xx::blocks_add_xx() {}
blocks_add_xx::~blocks_add_xx() {}
cppPair blocks_add_xx::assembleStmt(blockInfo bi) {
  cppPair res;

  id = bi.find("id");
  _enabled = bi.find("_enabled");
  if (_enabled == "False") {
    return res;
  }
  type = bi.find("type");
  vlen = bi.find("vlen");

  string stmt;
  stmt += INDENT;
  if (type == "float") {
    stmt += "gr::blocks::add_ff::sptr";
  }
  stmt += " ";
  stmt += id;
  stmt += " ";
  stmt += "=";
  stmt += " ";
  if (type == "float") {
    stmt += "gr::blocks::add_ff::make";
  }
  stmt += "(";
  stmt += vlen;
  stmt += ")";
  stmt += ";";

  res.header = "#include <gnuradio/blocks/add_ff.h>";
  res.stmt = stmt;

  return res;
}

const object *blocks_add_xx::theObject = object::Register<blocks_add_xx>("blocks_add_xx");
