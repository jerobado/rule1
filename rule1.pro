# Commands:
# > qmake -o Makefile rule1.pro     -> to generate a makefile
# > make                            -> run make

QT -= qui # use only the core module

CONFIG += c++latest console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    rule1.cpp

debug:DESTDIR = build/debug         # for debugging/development
release:DESTDIR = build/release     # for releasing/production

TARGET = rule1

DISTFILES += \
    .gitignore \
    README.md \
    _todo.txt
