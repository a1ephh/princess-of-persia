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

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
