Patch GnuTLS package (See https://www.msys2.org/wiki/Creating-Packages/)
```sh
git clone https://github.com/msys2/MINGW-packages
cd MINGW-packages/mingw-w64-gnutls
patch -p2 <<<EOF
diff --git a/mingw-w64-gnutls/PKGBUILD b/mingw-w64-gnutls/PKGBUILD
index cc92ba84a..ee6a3f252 100644
--- a/mingw-w64-gnutls/PKGBUILD
+++ b/mingw-w64-gnutls/PKGBUILD
@@ -70,6 +70,9 @@ build() {
     --disable-gtk-doc \
     --with-libiconv-prefix=${MINGW_PREFIX} \
     --with-libregex-libs=-lsystre \
+    --without-p11-kit \
+    --without-idn \
+    --with-included-unistring \
     --enable-local-libopts \
     --disable-guile \
     --disable-libdane \

EOF
```

Build (linker will fail)
```sh
mkdir build
cd build
cmake -G "MSYS Makefiles" -DCMAKE_BUILD_TYPE=MinSizeRel -DBUILD_STATIC=1 -DENABLE_NLS=OFF -DCMAKE_MAKE_PROGRAM=mingw32-make -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
cmake --build . --target vncviewer -j $(nproc)
```

Link binary
```sh
set -e
cd vncviewer
g++ -pthread -Wall -Wformat=2 -Os -DNDEBUG -UNDEBUG  -nodefaultlibs -mwindows -Wl,--whole-archive CMakeFiles/vncviewer.dir/objects.a -Wl,--no-whole-archive -o vncviewer.exe -Wl,--major-image-version,0,--minor-image-version,0  ../common/rfb/librfb.a ../common/network/libnetwork.a ../common/rdr/librdr.a ../common/os/libos.a -Wl,-Bstatic -lfltk_images -lpng -ljpeg -lfltk -Wl,-Bdynamic -lcomctl32 -Wl,-Bstatic -lintl -liconv -Wl,-Bdynamic -lmsimg32 -Wl,-Bstatic -lz -Wl,-Bdynamic -Wl,-Bstatic -ljpeg -Wl,-Bdynamic -Wl,-Bstatic -lpixman-1 -Wl,-Bdynamic -Wl,-Bstatic -lgnutls -ltasn1 -lhogweed -lnettle -lgmp -Wl,-Bdynamic -lcrypt32 -lbcrypt -lncrypt -lws2_32 -Wl,-Bstatic -lz -Wl,-Bdynamic -Wl,-Bstatic -lintl -liconv -Wl,-Bdynamic -lws2_32 -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32  -Wl,-Bstatic -lstdc++ -lwinpthread -lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -Wl,-Bdynamic -lmsvcrt -luser32 -lkernel32 -ladvapi32 -lshell32 -lmsvcrt
strip --strip-unneeded vncviewer.exe
```
