#!/usr/bin/env bash

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
cd "$SCRIPT_DIR" || exit 1

cd ../../../.. || exit 1

git submodule init
git submodule update

KEYBOARD="planck/rev7"
KEYMAP="planck_keymap"
TARGET="$KEYBOARD:$KEYMAP"

util/docker_build.sh $TARGET || exit 1

OUTPUT_BIN="planck_rev7_planck_keymap.bin"
DEVICE_ADR="0483:DF11"

dfu-util --alt 0 --device $DEVICE_ADR --wait $DEVICE_ADR --dfuse-address 0x8000000:leave --download $OUTPUT_BIN
