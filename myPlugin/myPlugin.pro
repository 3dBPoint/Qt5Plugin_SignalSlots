HEADERS += \
    plugin.h

SOURCES += \
    plugin.cpp

QT += widgets

TARGET = Plugin
TEMPLATE = lib
INCLUDEPATH += $$PWD/../PluginInterface
DEPENDPATH += $$PWD/../PluginInterface

LIBS += -L$$PWD/../PluginInterface/lib/ -lPluginInterface
DESTDIR = ../app/debug
