with (import <nixpkgs> {});

stdenv.mkDerivation rec {
  name = "avrocheck";
  builder = "${bash}/bin/bash";
  args = [ ./builder.sh ];

  buildInputs = [ gcc7 cmake avro-cpp boost];
  baseInputs  = [ gcc7 findutils bash gnutar gzip gnumake protobuf binutils coreutils gawk gnused gnugrep ];

  setup = ./setup.sh;
  src = ".";
  system = builtins.currentSystem;
}
