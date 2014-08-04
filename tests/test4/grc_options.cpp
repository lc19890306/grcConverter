#include "grc_options.h"

options::options() {}
options::~options() {}
string options::assembleStmt(blockInfo bi) {
  string res;

  id = bi.find("id");
  _enabled = bi.find("_enabled");
  res += INDENT;
  res += "gr::top_block_sptr";
  res += " ";
  res += "tb";
  res += " ";
  res += "gr::make_top_block";
  res += "(";
  res += "\"";
  res += id;
  res += "\"";
  res += ")";
  res += ";";

  return res;
}

const object *options::theObject = object::register<options>("options");
