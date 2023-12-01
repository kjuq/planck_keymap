#!/usr/bin/env bash

# cd to the directory where the script is located
cd "$(dirname "$0")" || exit 1

export PATH="$HOME/Library/xPacks/@xpack-dev-tools/arm-none-eabi-gcc/11.3.1-1.1.2/.content/bin:$PATH"

if command -v qmk > /dev/null 2>&1 ; then
    qmk flash -kb planck/rev7 -km planck_keymap
else
    cd ../../../.. || exit 1
    make planck/rev7:planck_keymap:dfu-util
fi
