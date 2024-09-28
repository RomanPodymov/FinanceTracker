QT += core gui widgets network

CONFIG += c++20

SOURCES += \
    App/main.cpp \
    App/accountsscreen.cpp \
    App/signinscreen.cpp \
    App/registerscreen.cpp \
    App/coordinator.cpp \
    # BackendlessQt
    BackendlessQt/BasicAPI.cpp \
    BackendlessQt/BackendlessAPI.cpp \
    BackendlessQt/BackendlessUserAPI.cpp \
    BackendlessQt/BackendlessUser.cpp

HEADERS += \
    App/accountsscreen.hpp \
    App/signinscreen.hpp \
    App/registerscreen.hpp \
    App/coordinator.hpp \
    # BackendlessQt
    BackendlessQt/BasicAPI.hpp \
    BackendlessQt/BackendlessAPI.hpp \
    BackendlessQt/BackendlessUserAPI.hpp \
    BackendlessQt/BackendlessUser.hpp \

RESOURCES += \
    App/appresources.qrc
