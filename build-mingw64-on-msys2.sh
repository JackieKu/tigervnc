#!/bin/bash
exec cmake -G "MSYS Makefiles" -DCMAKE_BUILD_TYPE=MinSizeRel -DBUILD_STATIC=1 -DENABLE_NLS=OFF -DCMAKE_MAKE_PROGRAM=mingw32-make -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
