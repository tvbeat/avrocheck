cmake_minimum_required(VERSION 3.5)
project(ae C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake" ${CMAKE_INCLUDE_PATH})
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-fPIC -Wall --std=c++17")
set(CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")

set(STATIC_LINKING FALSE CACHE BOOL "Build a static binary?")

if(STATIC_LINKING)
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
  set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
  find_package (ZLIB REQUIRED)
  set(Boost_USE_STATIC_LIBS ON)
endif(STATIC_LINKING)

# boost
find_package(Boost COMPONENTS program_options iostreams REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# avro
find_package (AvroCPP REQUIRED)
include(avrogen)
include_directories(${AVRO_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# avro stubs
avro_generate_class("avro/disref_cust_card_sum_hist_tvbeat.avsc" "subs.avro.h"      sky SubsAvroHeader)
avro_generate_class("avro/ods_ams_q_tvbeat.avsc"                 "evts_q.avro.h"    sky EvtsAvroHeaderQ)
avro_generate_class("avro/ods_ams_plus_tvbeat.avsc"              "evts_plus.avro.h" sky EvtsAvroHeaderPlus)
avro_generate_class("avro/oss_bss_epg_sched_tvbeat.avsc"         "bss_epg.avro.h"   sky EpgSchedAvroHeader)

#
add_executable(avrocheck
  ${SubsAvroHeader}
  ${EvtsAvroHeaderQ}
  ${EvtsAvroHeaderPlus}
  ${EpgSchedAvroHeader}
  main.cc
  stats.cc)

if(STATIC_LINKING)

  target_link_libraries(avrocheck
    stdc++fs
    ${AVRO_LIBRARIES}
    ${Boost_LIBRARIES}
    ${ZLIB_LIBRARIES})

else(STATIC_LINKING)

  target_link_libraries(avrocheck
    stdc++fs
    ${AVRO_LIBRARIES})

endif(STATIC_LINKING)

#
include(GNUInstallDirs)
install(TARGETS avrocheck DESTINATION ${CMAKE_INSTALL_BINDIR})
