TEMPLATE = app

QT += core gui widgets network

CONFIG += c++20

SOURCES += \
    main.cpp \
    signinscreen.cpp \
    registerscreen.cpp

HEADERS += \
    signinscreen.hpp \
    registerscreen.hpp

INCLUDEPATH += \
    ../BackendlessQt

LIBS += \
    -L../BackendlessQt -lBackendlessQt
