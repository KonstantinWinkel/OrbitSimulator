cd "$(dirname "$0")/.." || exit 128

mkdir build
cd build

cmake .. $@

make
