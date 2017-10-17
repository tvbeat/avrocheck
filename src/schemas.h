#ifndef AVROCHECK_SCHEMAS_H_
#define AVROCHECK_SCHEMAS_H_

#include "subs.avro.h"
struct avro_subscriber_meta {
  using type                          = sky::disref_cust_card_sum_hist;
  static constexpr const char* schema = "disref_cust_card_sum_hist_tvbeat.avsc";
};

#include "evts_plus.avro.h"
struct avro_events_plus {
  using type                          = sky::ods_ams_plus;
  static constexpr const char* schema = "ods_ams_plus_tvbeat.avsc";
};

#include "evts_q.avro.h"
struct avro_events_q {
  using type                          = sky::ods_ams_q;
  static constexpr const char* schema = "ods_ams_q_tvbeat.avsc";
};

#endif // AVROCHECK_SCHEMAS_H_
