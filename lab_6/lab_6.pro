TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        neuronnet.cpp \
        perceptron.cpp

HEADERS += \
    neuronnet.h \
    perceptron.h
