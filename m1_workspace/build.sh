#!/bin/bash

set -e

BUILD_DIR="build"

function build() {
  if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
  fi
  cd $BUILD_DIR
  cmake ..
  make
  mv *_example ../
  cd ..
}

function run() {
  if [ -d "$BUILD_DIR" ]; then
    ./boost_example
    ./gtest_example
  else
    echo "Build directory does not exist. Please run 'sh build.sh build' first."
    exit 1
  fi
}

function clean() {
  if [ -d "$BUILD_DIR" ]; then
    echo "execute shell command: rm -rf $BUILD_DIR"
    rm -rf $BUILD_DIR
  fi
}

case "$1" in
  build)
    build
    ;;
  run)
    run
    ;;
  clean)
    clean
    ;;
  *)
    echo "Usage: sh build.sh {build|run|clean}"
    exit 1
    ;;
esac
