#!/usr/bin/env bash

set -e

tmpdir=$(mktemp -d)

git checkout-index -a -f --prefix=${tmpdir}/

# build container
docker build -t tvbeat/avrocheck .

# clean
docker run -it --rm -v $(pwd):/source tvbeat/avrocheck make clean

# build source
docker run -it --rm -v $(pwd):/source tvbeat/avrocheck make install \
                                                       TARGET=release \
                                                       STATIC=1

cp out/bin/avrocheck $tmpdir

HEAD_SHA=$(git rev-parse --short HEAD)
out_file=avrocheck-${HEAD_SHA}.tar.gz

tar cjf $out_file -C $tmpdir .

rm -rf $tmpdir

echo done bundling! out: ${out_file}
