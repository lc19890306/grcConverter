#include "grc_strop.h"
/*
bool startswith(string str, string prefix) {
  if (str.empty()) {
    return false;
  }
  else if (str.find(prefix) == 0) {
    return true;
  }
  else {
    return false;
  }
}

vector<string> arrangeArgv(int argc, char **argv) {
  vector<string> newArgv(2);
  string prefix = "-";
  newArgv[0] = argv[0];

  for (int i = 1; i < argc; ++i) {
    string str = argv[i];
    if (startswith(str, prefix)) {
      newArgv.push_back(str);
    }
    else {
      if (newArgv[1].empty()) {
	newArgv[1] = str;
      }
    }
  }

  return newArgv;
}

bool isLegal(string filename, vector<string> fileExt, string &source, unsigned &index) {
  int i;
  for (i = 0; i < fileExt.size(); ++i) {
    index = filename.find_last_of('.') + 1;
    if (filename.substr(index) == fileExt[i]) {
      source = fileExt[i];
      return true;
    }
  }

  return false;
}

string replaceFileExt(string filename, string source, unsigned index,  string outputFormat) {
  filename.replace(index, source.size(), outputFormat);

  return filename;
}

vector<string> split(string &str,const char *c) {
  char *cstr, *p;
  vector<string> res;
  cstr = new char[str.size()+1];
  strcpy(cstr, str.c_str());
  p = strtok(cstr, c);
  while(p != NULL)
    {
      res.push_back(p);
      p = strtok(NULL, c);
    }

  return res;
}

options getOpts(vector<string> argv) {
  options res;
  string prefix = "-";
  string key_funcname = "--funcname=";
  string key_phi = "--phi=";
  string key_pathlen = "--pathlen=";
  string key_datatype = "--datatype=";

  for (int i = 0; i < argv.size(); ++i) {
    if (startswith(argv[i], key_funcname)) {
      string funcName = argv[i].substr(key_funcname.size());
      assert(!funcName.empty() && "target function name should be given");
      res.addFuncName(funcName);
    }
    if (startswith(argv[i], key_phi)) {
      string phi = argv[i].substr(key_phi.size());
      assert(!phi.empty() && "the value of phi should be given");
      res.addPhi(phi);
    }
    if (startswith(argv[i], key_pathlen)) {
      string pathLen = argv[i].substr(key_pathlen.size());
      assert(!pathLen.empty() && "the length of path should be given");
      res.addPathLen(pathLen);
    }
    if (startswith(argv[i], key_datatype)) {
      string dataType = argv[i].substr(key_datatype.size());
      assert(!dataType.empty() && "a data type should be given");
      res.addDataType(dataType);
    }
    if (startswith(argv[i], prefix)) {
      res.add(argv[i]);
    }
  }

  return res;
}
*/
string strip(const string &str, const string &target) {
  string res;

  string::size_type start = 0, end = 0;
  start = str.find_first_not_of(target);
  end = str.find_last_not_of(target);
  res = str.substr(start, end - start + 1);

  return res;
}

bool isInt(const string &str) {
  if (str.empty()) {
    return false;
  }
  if (str.find(".") == string::npos) {
    return true;
  }
  else {
    return false;
  }
}

/*
string removeVarName(const string str) {
  string res;

  string::size_type pos;
  pos = str.find_last_of(' ');
  res = str.substr(0, pos + 1);
  pos = res.find_last_not_of(' ');
  res = res.substr(0, pos + 1);

  return res;
}

string replaceDataType(const string &classType, const string &dataType) {
  string res = classType;

  int len = 0;

  string::size_type start, end;
  start = classType.find("<");
  end = classType.find_last_of(">");
  if (start != string::npos) {
    len = end - start - 1;
    res = res.replace(start + 1, len, dataType);
  }

  return res;
}

string replaceAll(const string &str, const string &substr, const string &target) {
  string res = str;

  string::size_type start;
  start = res.find(target);
  int len = target.length();
  while (start != string::npos) {
    res = res.replace(start, len, substr);
    start = res.find(target);
  }

  return res;
}
*/
