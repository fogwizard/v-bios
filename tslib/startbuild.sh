#1.install gun M4 under autogen dir (./configure make make install)
#2.install autoconf in autoconf dir 
#3.install automake in automake dir 
#4.install libtool  in libtool  dir 
# cancel the dir palse now ,so such install in system
if [ "$1" = "?" ]; then
	echo "(1)source build/envsetup.sh in this dir and don't source in father dir(too high arm-linux-g++)"
	echo "(2)./startbuild ,As this script do it..." 
	echo "(3)make && make install (install should be sudo )"
	exit 1
fi
./autogen.sh
echo "ac_cv_func_malloc_0_nonnull=yes" >arm-linux.cache
./configure --host=arm-none-linux-gnueabi  --cache-file=arm-none-linux-gnueabi.cache --enable-inputapi=no  --prefix=$PWD/out
