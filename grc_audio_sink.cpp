#include "grc_audio_sink.h"

audio_sink::audio_sink() {}
audio_sink::~audio_sink() {}
cppPair audio_sink::assembleStmt(blockInfo bi) {
  cppPair res;

  id = bi.find("id");
  _enabled = bi.find("_enabled");
  if (_enabled == "False") {
    return res;
  }
  samp_rate = bi.find("samp_rate");

  string stmt;
  stmt += INDENT;
  stmt += "gr::audio::sink::sptr";
  stmt += " ";
  stmt += id;
  stmt += " ";
  stmt += "=";
  stmt += " ";
  stmt += "gr::audio::sink::make";
  stmt += "(";
  stmt += samp_rate;
  stmt += ")";
  stmt += ";";

  res.header = "#include <gnuradio/audio/sink.h>";
  res.stmt = stmt;

  return res;
}

const object *audio_sink::theObject = object::Register<audio_sink>("audio_sink");
