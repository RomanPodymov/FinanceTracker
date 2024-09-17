TEMPLATE = app

QT += core gui widgets network

CONFIG += c++20

SOURCES += \
    main.cpp \
    accountsscreen.cpp \
    signinscreen.cpp \
    registerscreen.cpp \
    coordinator.cpp

HEADERS += \
    accountsscreen.hpp \
    signinscreen.hpp \
    registerscreen.hpp \
    coordinator.hpp

INCLUDEPATH += \
    ../BackendlessQt

LIBS += \
    -L../BackendlessQt -lBackendlessQt

RESOURCES += \
    appresources.qrc

ios {
    QMAKE_TARGET_BUNDLE_PREFIX = com.finance
    QMAKE_DEVELOPMENT_TEAM = YOUR_DEVELOPMENT_TEAM
    QMAKE_INFO_PLIST = iOS/Info.plist
    ios_icon.files = $$files($$PWD/iOS/Icon.xcassets)
    QMAKE_BUNDLE_DATA += ios_icon
}
