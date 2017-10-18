#ifndef AVROCHECK_SCHEMAS_H_
#define AVROCHECK_SCHEMAS_H_

//FINAL_CUSTOMER_CARD_SUMMARY_HISTORY_1485990000_1486076400.avro
#include "subs.avro.h"
struct avro_subscriber_meta {
  using type                          = sky::disref_cust_card_sum_hist;
  static constexpr const char* schema = "disref_cust_card_sum_hist_tvbeat.avsc";
};

//ATOMIC_AMS_VIEWING_EVENTS_ODS_1487271600_1487275200.avro
#include "evts_plus.avro.h"
struct avro_events_plus {
  using type                          = sky::ods_ams_plus;
  static constexpr const char* schema = "ods_ams_plus_tvbeat.avsc";
};

//ATOMIC_ETHAN_AMS_VIEWING_EVENTS_ODS_1485932400_1485936000.avro
#include "evts_q.avro.h"
struct avro_events_q {
  using type                          = sky::ods_ams_q;
  static constexpr const char* schema = "ods_ams_q_tvbeat.avsc";
};

//ATOMIC_BSS_EPG_SCHEDULE_ODS_1485990000_1486076400.avro
#include "bss_epg.avro.h"
struct bss_epg_sched {
  using type                          = sky::ods_bss_epg_sched;
  static constexpr const char* schema = "oss_bss_epg_sched_tvbeat.avsc";
};

//ATOMIC_NDS_PROGRAMME_KEY_ODS_1485990000_1486076400.avro
#include "nds_programme_key.avro.h"
struct nds_pgm_key {
  using type                          = sky::ods_nds_progkey;
  static constexpr const char* schema = "nds_programme_key_tvbeat.avsc";
};

//ATOMIC_BSS_HINT_SCHEDULE_ODS_1485990000_1486076400.avro
#include "bss_hint_sched.avro.h"
struct  bss_hint_sched{
  using type                          = sky::ods_bss_hintsched;
  static constexpr const char* schema = "bss_hint_sched_tvbeat.avsc";
};

//ATOMIC_SKYIQ_SERVICE_KEY_ATTRIBUTES_DESCRIPTION_1485990000_1486076400.avro
#include "srv_key_attr_descr.avro.h"
struct  service_key_attr_desc{
  using type                          = sky::ods_skyiq_servkey_attr_desc;
  static constexpr const char* schema = "service_key_attr_descr_tvbeat.avsc";
};

//ATOMIC_SKYIQ_SERVICE_KEY_ATTRIBUTES_ODS_1485990000_1486076400.avro
#include "srv_key_attr_ods.avro.h"
struct  service_key_attr{
  using type                          = sky::ods_skyiq_servkey_attr;
  static constexpr const char* schema = "service_key_attr_ods_tvbeat.avsc";
};

//ATOMIC_SKYIQ_SERVICE_KEY_CODE_MAPPING_ODS_1485990000_1486076400.avro
#include "srv_key_code_map.avro.h"
struct  service_key_codemap{
  using type                          = sky::ods_skyiq_servkey_codemap;
  static constexpr const char* schema = "service_key_code_map_tvbeat.avsc";
};

/*
//TRP_SPORTS_METADATA.avro
#include "trp_sport_meta.avro.h"
struct  {
  using type                          = sky::csv_to_avro;
  static constexpr const char* schema = "trp_sport_meta_tvbeat.avsc";
};

ATOMIC_TANDBERG_VOD_ASSET_ODS_1485990000_1486076400.avro
---------- odbc_to_avro!!!
#include "vod_asset.avro.h"
struct  {
  using type                          = sky::odbc_to_avro;
  static constexpr const char* schema = "vod_asset_tvbeat.avsc";
};
ATOMIC_OLIVE_SPORTS_PROGRAMMES_METADATA_ODS_1485907200_1485993600.avro
---------- odbc_to_avro !!!
#include "olive_sport_meta.avro.h"
struct  {
  using type                          = sky::odbc_to_avro;
  static constexpr const char* schema = "olive_sport_meta_tvbeat.avsc";
};
*/
#endif // AVROCHECK_SCHEMAS_H_
