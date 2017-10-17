#ifndef AVROCHECK_AVRO_READER_H_
#define AVROCHECK_AVRO_READER_H_

#include "avro/ValidSchema.hh"
#include "avro/Compiler.hh"
#include "avro/DataFile.hh"
#include <string>
#include <fstream>
#include <experimental/optional>
#include <experimental/filesystem>
#include <cstdlib>
#include <iostream>

namespace fs = std::experimental::filesystem;

template <typename AvroClass>
struct avro_reader {
  using record_type = typename AvroClass::type;

  avro_reader()
    : schema_(avro_reader::load_schema())
    , reader_(new avro::DataFileReader<record_type>("/dev/stdin", schema_)) {}

  ~avro_reader() {delete reader_;}

  template<typename T, typename Fn, typename Err>
  void reduce(T &acc, Fn fn, Err err) {
    record_type ac;
    while (reader_->read(ac)) {
      try         { fn(ac, acc);}
      catch (...) { err(acc);   }
    }
  }

private:
  static avro::ValidSchema load_schema() {
    avro::ValidSchema schema;
    auto full_path = fs::path(::getenv("AE_SHARE")) / AvroClass::schema;
    std::ifstream ifs(full_path);
    avro::compileJsonSchema(ifs, schema);
    return schema;
  }

  const avro::ValidSchema schema_;
  avro::DataFileReader<record_type> *reader_;
};

#endif //AVROCHECK_AVRO_READER_H_
