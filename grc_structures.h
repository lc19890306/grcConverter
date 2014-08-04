#ifndef __H_GRC_STRUCTURES_
#define __H_GRC_STRUCTURES_

#include <vector>
#include <string>
#include <set>
#include <fstream>

using namespace std;

class paramInfo {
 public:
  paramInfo() {}
 paramInfo(const string key, const string value): key(key), value(value) {}
  ~paramInfo() {}

  void setKey(const string key) {
    this->key = key;
  }
  string getKey() const {
    return key;
  }
  void setValue(const string value) {
    this->value = value;
  }
  string getValue() const {
    return value;
  }

 private:
  string key;
  string value;
};

class blockInfo {
 public:
  blockInfo() {}
 blockInfo(const string key): key(key) {}
  ~blockInfo() {}
  void setKey(const string key) {
    this->key = key;
  }
  string getKey() const {
    return key;
  }
  void addParam(const paramInfo pi) {
    params.push_back(pi);
  }
  string find(const string key) {
    vector<paramInfo>::iterator iter;
    for (iter = params.begin(); iter != params.end(); ++iter) {
      if (iter->getKey() == key) {
	return iter->getValue();
      }
    }
    return NULL;
  }
  vector<paramInfo> getParams() const {
    return params;
  }

 private:
  string key;
  vector<paramInfo> params;
};

class connectionInfo {
 public:
  connectionInfo() {}
 connectionInfo(const string source_block_id, const string sink_block_id, const string source_key, const string sink_key):
  source_block_id(source_block_id), sink_block_id(sink_block_id), source_key(source_key), sink_key(sink_key) {}
  ~connectionInfo() {}
  void setSourceBlockId(const string source_block_id) {
    this->source_block_id = source_block_id;
  }
  string getSourceBlockId() const {
    return source_block_id;
  }
  void setSinkBlockId(const string sink_block_id) {
    this->sink_block_id = sink_block_id;
  }
  string getSinkBlockId() const {
    return sink_block_id;
  }
  void setSourceKey(const string source_key) {
    this->source_key = source_key;
  }
  string getSourceKey() const {
    return source_key;
  }
  void setSinkKey(const string sink_key) {
    this->sink_key = sink_key;
  }
  string getSinkKey() const {
    return sink_key;
  }

  string createStmt() const {
    string res = "connect";
    res += "(";
    res += source_block_id;
    res += ",";
    res += " ";
    res += source_key;
    res += ",";
    res += " ";
    res += sink_block_id;
    res += ",";
    res += " ";
    res += sink_key;
    res += ")";
    res += ";";

    return res;
  }

 private:
  string source_block_id;
  string sink_block_id;
  string source_key;
  string sink_key;
};

typedef vector<paramInfo> vParam;
typedef vector<blockInfo> vBlock;
typedef vector<connectionInfo> vConnection;
typedef blockInfo* blockInfoPtr;
typedef connectionInfo* connectionInfoPtr;
typedef paramInfo* paramInfoPtr;
typedef struct {
  string header;
  string stmt;
} cppPair;

class cppFile {
 public:
  cppFile(string filename) {
    fout.open(filename.c_str());
  }
  ~cppFile() {
    fout.close();
  }

  void push_back(const cppPair pair) {
    if (headers.count(pair.header) == 0) {
      headers.insert(pair.header);
    }
    body.push_back(pair.stmt);
  }

  void push_back(const string str) {
    body.push_back(str);
  }

  void print() {
    for (set<string>::iterator iter = headers.begin(); iter != headers.end(); ++iter) {
      std::cout << *iter << std::endl;
      if (!iter->empty()) {
	fout << *iter << std::endl;
      }
    }
    for (unsigned i = 0; i < body.size(); ++i) {
      std::cout << body[i] << std::endl;
      fout << body[i] << std::endl;
    }
  }

 private:
  set<string> headers;
  vector<string> body;
  ofstream fout;
};

#endif // __H_GRC_STRUCTURES_
