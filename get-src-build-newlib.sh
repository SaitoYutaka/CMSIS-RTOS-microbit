#!/bin/bash

git clone https://github.com/ARM-software/CMSIS_5.git
cd CMSIS_5
git checkout 5.7.0
patch -p1 < ../disable-software_init_hook-rt_systick_init.patch
cd ..

git clone https://github.com/NordicSemiconductor/nrfx.git
cd nrfx
git checkout v2.3.0
cd ..

git clone https://sourceware.org/git/newlib-cygwin.git
cd newlib-cygwin
git checkout newlib-3.3.0

mkdir build
cd build
../configure --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=arm-none-eabi --disable-newlib-supplied-syscalls --enable-newlib-reent-check-verify --enable-newlib-reent-small --enable-newlib-retargetable-locking --disable-newlib-fvwrite-in-streamio --disable-newlib-fseek-optimization --disable-newlib-wide-orient --enable-newlib-nano-malloc --disable-newlib-unbuf-stream-opt --enable-lite-exit --enable-newlib-global-atexit --enable-newlib-nano-formatted-io --disable-nls
CFLAGS='-g -Os -ffunction-sections -fdata-sections' make -j4
