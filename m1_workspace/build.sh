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
  mv gtest_* ../
  cd ..
}

function run() {
  if [ -d "$BUILD_DIR" ]; then
    ./gtest_example
    ./gtest_thread
  else
    echo "Build directory does not exist. Please run 'sh build.sh build' first."
    exit 1
  fi
}

function clean() {
  if [ -d "$BUILD_DIR" ]; then
    echo "execute shell command: rm -rf $BUILD_DIR"
    echo "execute shell command: rm -rf ./gtest_* "
    rm -rf $BUILD_DIR
    rm -rf ./gtest_*
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
