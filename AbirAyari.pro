QT       += core gui network sql multimedia serialport texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accesscard.cpp \
    client.cpp \
    conge.cpp \
    connection.cpp \
    connecxion.cpp \
    employe.cpp \
    exportexcelobject.cpp \
    main.cpp \
    mainwindow.cpp \
    peermanager.cpp \
    rh.cpp \
    server.cpp \
    smtp.cpp

HEADERS += \
    accesscard.h \
    client.h \
    conge.h \
    connection.h \
    connecxion.h \
    employe.h \
    exportexcelobject.h \
    mainwindow.h \
    peermanager.h \
    rh.h \
    server.h \
    smtp.h

FORMS += \
    mainwindow.ui \
    rh.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc
