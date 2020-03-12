# Qt Core wrapper for [librtclient](http://darapsa.org/librtclient)

# Building

## Getting

```sh
$ git clone git://darapsa.org/qrtclient.git
$ cd qrtclient
```

## Configuring for various target hosts (with optional debugging)

```sh
$ qmake CONFIG+=debug -spec android-clang qrtclient.pro
```

or

```sh
$ qmake CONFIG+=debug -spec linux-g++ qrtclient.pro
```

or

```sh
$ qmake CONFIG+=debug -spec macx-clang qrtclient.pro
```

or

```sh
$ qmake CONFIG+=debug -spec macx-ios-clang qrtclient.pro
```

or so on.

## Compiling and linking

```sh
$ make # -jN (with N an integer number of parallel tasks you allow your computer to run for compiling this)
```
