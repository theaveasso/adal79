#!/bin/sh

set -e

BUILD_DIR="build"
BUILD_TYPE="Debug"

if [[ "$1" == "Release" || "$1" == "release" ]]; then
  BUILD_TYPE="Release"
fi

cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
cmake --build build

set +e
