QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    invitation.cpp \
    invite.cpp \
    main.cpp \
    mainwindow.cpp \
    table.cpp

HEADERS += \
    connexion.h \
    invitation.h \
    invite.h \
    mainwindow.h \
    table.h

FORMS += \
    invitation.ui \
    invite.ui \
    mainwindow.ui \
    table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    img/6512.jpg \
    img/6951.jpg \
    img/employes-celebrant-anniversaire.jpg \
    img/flat-design-ethical-dilemma-with-woman_23-2148711126.jpg \
    img/gens-cadeaux.jpg \
    img/patron-epouse-ss-back.png \
    img/patron-epouse.jpg \
    img/user-edit-solid.svg \
    img/user-times-solid.svg \
    img/users-solid.svg
