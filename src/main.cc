#include "schemas.h"
#include "avro_reader.h"
#include "stats.h"

#include "avro/ValidSchema.hh"
#include "avro/Compiler.hh"
#include "avro/DataFile.hh"

#include <unistd.h>


static void usage() {
  puts("usage: \n"
       "avrocheck sub_meta|plus_events|q_events|epg_sched|nds_pgm_key|hint_sched|sk_attr|sk_attr_desc|sk_codemap\n"
       "avro file should be provided from standard input\n"
       "AE_SHARE should point to directory with avsc files (schema definitions)");
}

template <typename T>
void read_from_input_stream() {
  try {
    avro_reader<T> reader;
    puts("schema loaded");

    int _;
    reader.reduce( _
                 , [](const typename T::type &, int&) { stats::count("records read"); }
                 , [](int&)                           { stats::count("read errors");  }
                 );
  } catch (avro::Exception &e) {
    printf("error: %s\n", e.what());
  }
  stats::dump();
}

int main(int argc, char **argv) {
  if (argc != 2 or ::isatty(STDIN_FILENO)) {
    usage();
    return -1;
  }

  std::string type = argv[1];
  if      (type == "sub_meta"    ) { read_from_input_stream<avro_subscriber_meta>();  }
  else if (type == "plus_events" ) { read_from_input_stream<avro_events_plus>();      }
  else if (type == "q_events"    ) { read_from_input_stream<avro_events_q>();         }
  else if (type == "epg_sched"   ) { read_from_input_stream<bss_epg_sched>();         }
  else if (type == "nds_pgm_key" ) { read_from_input_stream<nds_pgm_key>();           }
  else if (type == "hint_sched"  ) { read_from_input_stream<bss_hint_sched>();        }
  else if (type == "sk_attr"     ) { read_from_input_stream<service_key_attr>();      }
  else if (type == "sk_attr_desc") { read_from_input_stream<service_key_attr_desc>(); }
  else if (type == "sk_codemap"  ) { read_from_input_stream<service_key_codemap>();   }
  else                             { usage(); return -1; }
  return 0;

}
