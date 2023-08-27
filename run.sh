cmake -S . -B build
pushd build > /dev/null
make
popd
./build/flang test.fg