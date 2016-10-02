#! /bin/sh

D=~/prog/_lib_
cmake-mingw-w32 -DCMAKE_BUILD_TYPE=Release \
	-DBUILD_STATIC=ON \
	-DENABLE_NLS=OFF \
	-DCMAKE_PREFIX_PATH="$D/zlib_win32;$D/libjpeg_win32;$D/fltk_win32" \
	..
