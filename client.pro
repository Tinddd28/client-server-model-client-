QT       += core gui
QT += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adduser.cpp \
    clients.cpp \
    clientsd.cpp \
    dataout.cpp \
    deluser.cpp \
    director.cpp \
    edituser.cpp \
    items.cpp \
    itemsd.cpp \
    main.cpp \
    mainwindow.cpp \
    markmanager.cpp \
    mess.cpp \
    message.cpp \
    order.cpp \
    orders.cpp \
    sales_manager.cpp \
    setsale.cpp \
    users.cpp \
    usview.cpp

HEADERS += \
    adduser.h \
    clients.h \
    clientsd.h \
    dataout.h \
    deluser.h \
    director.h \
    edituser.h \
    items.h \
    itemsd.h \
    mainwindow.h \
    markmanager.h \
    mess.h \
    message.h \
    order.h \
    orders.h \
    sales_manager.h \
    setsale.h \
    users.h \
    usview.h

FORMS += \
    adduser.ui \
    clients.ui \
    clientsd.ui \
    dataout.ui \
    deluser.ui \
    director.ui \
    edituser.ui \
    items.ui \
    itemsd.ui \
    mainwindow.ui \
    markmanager.ui \
    mess.ui \
    message.ui \
    order.ui \
    orders.ui \
    sales_manager.ui \
    setsale.ui \
    users.ui \
    usview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
