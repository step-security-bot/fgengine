#!/bin/sh
source ../config.sh && \
clear && \
    make clean && \
    make -j $(( `nproc` - 1 )) && \
    clang-format --style='file:../.clang-format' \
    -i \
    src/*.cpp
