TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    base_container.cpp

HEADERS += \
    exceptions.h \
    matrix.h \
    matrix_iterator.h \
    matrix_iterator_const.h \
    base_container.h \
    matrix_iterator_const.hpp \
    matrix_iterator.hpp \
    matrix.hpp
