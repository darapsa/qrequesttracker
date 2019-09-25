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
LIBS += $$PWD/librtclient/librtclient.a

debug: DEFINES += DEBUG
