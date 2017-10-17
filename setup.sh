unset PATH

for p in $baseInputs $buildInputs; do
    export PATH=$p/bin${PATH:+:}$PATH
done

#CMAKE_MODULE_PATH=$cmake/share/cmake-3.8/Modules/


function build() {
    make install TARGET=release
}
