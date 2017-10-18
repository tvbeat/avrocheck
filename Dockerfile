FROM alpine:3.6
MAINTAINER Luka Blaskovic <lblasc@tvbeat.com>

ENV AVROCPP_URL=https://archive.apache.org/dist/avro/stable/cpp/avro-cpp-1.8.2.tar.gz

RUN set -x \
    && export CPU_COUNT=$(grep processor /proc/cpuinfo | wc -l) \
    && apk add --no-cache \
      autoconf \
      automake \
      bash \
      boost-dev \
      cmake \
      curl \
      file \
      git \
      g++ \
      libtool \
      linux-headers \
      make \
      openssl \
      openssl-dev \
      zlib-dev \
    && : "---------- avrocpp ----------" \
    && wget "$AVROCPP_URL" -O /tmp/avro-cpp.tar.gz \
    && mkdir /tmp/avro-cpp \
    && tar --strip-components=1 -xf /tmp/avro-cpp.tar.gz -C /tmp/avro-cpp \
    && (cd /tmp/avro-cpp; \
        cmake -G "Unix Makefiles"; \
        make -j$CPU_COUNT; \
        make install) \
    && ln -s /usr/local/lib/libavrocpp_s.a /usr/local/lib/libavrocpp.a \
    && : "---------- clean ----------" \
    && rm -rf /tmp/avro-cpp /tmp/avro-cpp.tar.gz \
    && mkdir /source

VOLUME ["/source"]
WORKDIR /source
CMD ["/bin/bash"]
