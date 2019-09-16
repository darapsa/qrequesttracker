QT -= gui
TEMPLATE = lib
CONFIG += staticlib

HEADERS += \
	qrtclient/user.hxx \
	qrtclient/ticket.hxx \
	qrtclient/client.hxx
SOURCES += \
	user.cxx \
	ticket.cxx \
	client.cxx

INCLUDEPATH += $$PWD/librtclient
LIBS += \
	$$PWD/librtclient/librtclient.a \
	-lcurl

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
	QMAKE_CFLAGS += -I/usr/local/aarch64-linux-android/sysroot/usr/include
	LIBS += -L/usr/local/aarch64-linux-android/sysroot/usr/lib
}

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
	QMAKE_CFLAGS += -I/usr/local/arm-linux-androideabi/sysroot/usr/include
	LIBS += -L/usr/local/arm-linux-androideabi/sysroot/usr/lib
}

debug: DEFINES += DEBUG
