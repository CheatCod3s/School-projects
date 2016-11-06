TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += \
    apufunktiot.cpp \
    kayttoliittyma.cpp \
    tiedostonluku.cpp \
    todo_rakenne.cpp \
    todo.cpp

HEADERS += \
    apufunktiot.hh \
    kayttoliittyma.hh \
    tiedostonluku.hh \
    todo_rakenne.hh

OTHER_FILES += \
    tht.txt

