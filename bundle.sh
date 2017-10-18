#!/usr/bin/env bash

set -e

tmpdir=$(mktemp -d)
curdir=$(pwd)

HEAD_SHA=$(git rev-parse --short HEAD)
ac_dir=${tmpdir}/avrocheck-${HEAD_SHA}

mkdir $ac_dir

git checkout-index -a -f --prefix=${ac_dir}/

# build container
docker build -t tvbeat/avrocheck $ac_dir

# build source
docker run -it --rm -v $ac_dir:/source tvbeat/avrocheck make install \
                                                        TARGET=release \
                                                        STATIC=1

cp $ac_dir/out/bin/avrocheck $ac_dir

# clean
docker run -it --rm -v $ac_dir:/source tvbeat/avrocheck make clean

out_file=avrocheck-${HEAD_SHA}.tar.gz
tar cjf $out_file -C $tmpdir .

rm -rf $tmpdir

echo done bundling! out: ${out_file}
