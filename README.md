# Qt Core wrapper for [librtclient](http://darapsa.org/librtclient)

# Building

## Getting

```sh
$ git clone git://darapsa.org/qrtclient.git
```

## Configuring for various target hosts (with optional debugging)

```sh
$ mkdir build-qrtclient-Desktop-Debug
$ cd build-qrtclient-Desktop-Debug
$ cmake -DCMAKE_BUILD_TYPE=Debug ../qrtclient
```

or

```sh
$ mkdir build-qrtclient-Android_for_armeabi_v7a_arm64_v8a_x86_x86_64_Clang_Qt_5_14_1_for_Android-Debug
$ cd build-qrtclient-Android_for_armeabi_v7a_arm64_v8a_x86_x86_64_Clang_Qt_5_14_1_for_Android-Debug
```

and then

```sh
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk-r21/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_ABI=arm64-v8a -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DCMAKE_BUILD_TYPE=Debug ../qrtclient
```

or

```sh
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk-r21/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_ABI=armeabi_v7a -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DCMAKE_BUILD_TYPE=Debug ../qrtclient
```

or

```sh
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk-r21/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_ABI=x86 -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DCMAKE_BUILD_TYPE=Debug ../qrtclient
```

or

```sh
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-ndk-r21/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt5.14.1/5.14.1/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_ABI=x86_64 -DCMAKE_INSTALL_PREFIX=/opt/Qt5.14.1/5.14.1/android -DCMAKE_BUILD_TYPE=Debug ../qrtclient
```

or so on.

## Compiling, linking, and installing

```sh
$ make # -jN (with N an integer number of parallel tasks you allow your computer to run for compiling this)
$ sudo make install
```
