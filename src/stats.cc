#include "stats.h"
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

static std::unordered_map<std::string, int> stats_;

void stats::count(const std::string &key, int inc) {
  auto it = stats_.find(key);
  if (it == std::end(stats_)) stats_.insert( { key, inc });
  else                        it->second += inc;
}

void stats::dump(int widht) {
  std::vector<std::string> keys;

  for (auto &p : stats_) {
    keys.push_back(p.first);
  }

  std::sort(std::begin(keys), std::end(keys));

  for (const auto &key : keys) {
    //auto &key   = p.first;
    auto count  = stats_[key];
    auto countw = (count > 0) ? std::floor(std::log10(count)) : 0;
    auto n      = widht - std::size(key) - countw - 3;

    ::printf("%s %s %u", key.c_str(), std::string(n, '.').c_str(), count);
  }
}
