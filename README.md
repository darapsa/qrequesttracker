# Qt Core wrapper for [librtclient](http://darapsa.org/librtclient)

# Building

## Getting

```sh
$ git clone git://darapsa.org/qrtclient.git
$ cd qrtclient
```

## Configuring for various target hosts (with optional debugging)

```sh
$ mkdir build
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
```

or

```sh
$ mkdir build-Android_arm64_v8a-Debug
$ cd build-Android_arm64_v8a-Debug
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_BUILD_ABI_arm64-v8a=1 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DANDROID_ABI=arm64-v8a -DCMAKE_CXX_STANDARD_LIBRARIES=/opt/android-ndk/sources/cxx-stl/llvm-libc++/libs/arm64-v8a/libc++_shared.so ..
```

or

```sh
$ mkdir build-Android_armeabi_v7a-Debug
$ cd build-Android_armeabi_v7a-Debug
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_BUILD_ABI_armeabi_v7a=1 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DANDROID_ABI=armeabi-v7a -DCMAKE_CXX_STANDARD_LIBRARIES=/opt/android-ndk/sources/cxx-stl/llvm-libc++/libs/armeabi-v7a/libc++_shared.so ..
```

or

```sh
$ mkdir build-Android_x86-Debug
$ cd build-Android_x86-Debug
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_BUILD_ABI_x86=1 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DANDROID_ABI=x86 -DCMAKE_CXX_STANDARD_LIBRARIES=/opt/android-ndk/sources/cxx-stl/llvm-libc++/libs/x86/libc++_shared.so ..
```

or

```sh
$ mkdir build-Android_x86_64-Debug
$ cd build-Android_x86_64-Debug
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_BUILD_ABI_x86_64=1 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DANDROID_ABI=x86_64 -DCMAKE_CXX_STANDARD_LIBRARIES=/opt/android-ndk/sources/cxx-stl/llvm-libc++/libs/x86_64/libc++_shared.so ..
```

or so on.

## Compiling, linking, and installing

```sh
$ make # -jN (with N an integer number of parallel tasks you allow your computer to run for compiling this)
$ sudo make install
```
