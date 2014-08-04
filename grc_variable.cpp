#include "grc_variable.h"

variable::variable() {}
variable::~variable() {}
cppPair variable::assembleStmt(blockInfo bi) {
  cppPair res;

  id = bi.find("id");
  _enabled = bi.find("_enabled");
  if (_enabled == "False") {
    return res;
  }
  value = bi.find("value");
  string dataType = (isInt(value)) ? "int" : "float";

  string stmt;
  stmt += INDENT;
  stmt += dataType;
  stmt += " ";
  stmt += id;
  stmt += " ";
  stmt += "=";
  stmt += " ";
  stmt += value;
  stmt += ";";

  res.stmt = stmt;

  return res;
}

const object *variable::theObject = object::Register<variable>("variable");
