TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    bbs.h \
    lcg.h \
    lecuyer.h \
    parkmiller.h \
    randomgenerator.h
