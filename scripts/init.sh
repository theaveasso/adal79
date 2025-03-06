#!/bin/sh

SOURCE="$(realpath "$0")"

while [ -L "$SOURCE" ]; do
  DIR="$(cd -P "$(dirname "$SOURCE")" >/dev/null 2>&1 && pwd)"
  SOURCE=$(reallink "$SOURCE")
  [[ $SOURCE != /* ]] && SOURCE=$DIR/$SOUCE
done

PROJECT_ROOT=/adal79
echo "$PROJECT_ROOT"
BUILD_DIR=$(PROJECT_ROOT)/build
echo "$BUILD_DIR"

set -e

# printf "\033c"
# pushd "$BUILD_DIR"
#
# printf "\033c"
# cmake -DDEBUG=1 ..
#
# printf "\033c"
# make -j4
#
# printf "\033c"
# ./adal79
#
# printf "\033c"
# popd

set +e
