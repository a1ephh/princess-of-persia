QT       += core gui widgets
CONFIG   += c++17

SOURCES += \
    main.cpp \
    game_status.cpp \
    mainwindow.cpp \
    obst.cpp \
    shop.cpp \
    shopwindow.cpp \
    weapons.cpp

HEADERS += \
    game_status.h \
    mainwindow.h \
    obst.h \
    shop.h \
    shopwindow.h \
    weapons.h

FORMS += \
    mainwindow.ui \
    shopwindow.ui

RESOURCES += \
    resources.qrc
