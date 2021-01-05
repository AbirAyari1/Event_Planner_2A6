QT       += core gui network multimedia sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    dialogeemmanuel.cpp \
    invitation.cpp \
    invites.cpp \
    main.cpp \
    smtpNgue.cpp \
    table.cpp

HEADERS += \
    connexion.h \
    dialogeemmanuel.h \
    invitation.h \
    invites.h \
    smtpNgue.h \
    table.h

FORMS += \
    dialogeemmanuel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

DISTFILES += \
    img/filter-solid (1).svg \
    img/print-solid.svg
