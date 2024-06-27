#!/bin/sh

export BOOST_VERSION=1.78.0
export BOOST_DIR=../boost_dir

wget https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz

# compile & build boost lib to ${BOOST_DIR}
tar xzf boost_1_78_0.tar.gz

cd boost_1_78_0
./bootstrap.sh --prefix=$BOOST_DIR

./b2 install
cd ..
