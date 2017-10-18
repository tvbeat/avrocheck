# avrocheck
Avro checker

## Running from the source

### Bootstrap docker container
```
docker build -t tvbeat/avrocheck .
```

### Build
```
docker run -it --rm -v $(pwd):/source tvbeat/avrocheck make install \
                                                       TARGET=release \
                                                       STATIC=1
```

### Run
```
./out/bin/avrocheck
```
