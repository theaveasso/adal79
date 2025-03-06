#!/bin/sh

source="$(realpath "$0")"
echo "$source"

while [ -L "$source" ]; do
  dir="$(cd -P "$(dirname "$source")" >/dev/null 2>&1 && pwd)"
  echo "$dir"
  source="$(readlink "$source")"  # Update source to the resolved symlink path
done
