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

#include "bss_epg.avro.h"
struct bss_epg_sched {
  using type                          = sky::ods_bss_epg_sched;
  static constexpr const char* schema = "oss_bss_epg_sched_tvbeat.avsc";
};

#include "nds_programme_key.avro.h"
struct nds_pgm_key {
  using type                          = sky::ods_nds_progkey;
  static constexpr const char* schema = "nds_programme_key_tvbeat.avsc";
};

#include "bss_hint_sched.avro.h"
struct  bss_hint_sched{
  using type                          = sky::ods_bss_hintsched;
  static constexpr const char* schema = "bss_hint_sched_tvbeat.avsc";
};

#include "srv_key_attr_descr.avro.h"
struct  service_key_attr_desc{
  using type                          = sky::ods_skyiq_servkey_attr_desc;
  static constexpr const char* schema = "service_key_attr_descr_tvbeat.avsc";
};

#include "srv_key_attr_ods.avro.h"
struct  service_key_attr{
  using type                          = sky::ods_skyiq_servkey_attr;
  static constexpr const char* schema = "service_key_attr_ods_tvbeat.avsc";
};

#include "srv_key_code_map.avro.h"
struct  service_key_codemap{
  using type                          = sky::ods_skyiq_servkey_codemap;
  static constexpr const char* schema = "service_key_code_map_tvbeat.avsc";
};

#include "trp_sport_meta.avro.h"
struct trp_sport_meta {
  using type                          = sky::csv_to_avro;
  static constexpr const char* schema = "trp_sport_meta_tvbeat.avsc";
};

#endif // AVROCHECK_SCHEMAS_H_
