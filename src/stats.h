#ifndef AVROCHECK_STATS_H_
#define AVROCHECK_STATS_H_

#include <string>

namespace stats {
  void count(const std::string &key, int inc = 1);
  void dump(int widht = 40);
}

#endif //AVROCHECK_STATS_H_
