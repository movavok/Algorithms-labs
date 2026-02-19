TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dataset.cpp \
        main.cpp \
        similarity.cpp

HEADERS += \
    dataset.h \
    recommender.h \
    similarity.h
