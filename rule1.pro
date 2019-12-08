QT -= qui # use only the core module

CONFIG += c++latest console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    rule1.cpp

# debug files
debug:DESTDIR = build/debug

# for releasing
release:DESTDIR = build/release
