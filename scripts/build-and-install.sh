cd "$(dirname "$0")/.." || exit 128

git submodule init
git submodule update

mkdir build
cd build

cmake .. $@

make

sudo make install