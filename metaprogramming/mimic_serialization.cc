#include <iostream>
#include <map>
#include <string>
#include <vector>

struct fly {
  std::string exchange;
};
static fly kkk;

// serialization data would be collected into `csvline`
std::vector<std::string> csvline;
// mapping of member name to list index
std::map<const char*, int> name2idx;

#define DESER(STRUCT, NAME, SRC, MAPTOIDX) STRUCT.NAME = SRC[MAPTOIDX.at(#NAME)]

void mimicSerAnalyse() {
  // mimic deserialize analysis from datafile(or string),
  // to object inside code
  DESER(kkk, exchange, csvline, name2idx);

  csvline[name2idx["kk"]];
}
