#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T16:52:39
#
#-------------------------------------------------

QT       += core gui sql printsupport multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SAV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    login.cpp \
        main.cpp \
        mainwindow.cpp \
    avis.cpp \
    suggestion.cpp \
    reclamation.cpp \
    connection.cpp \
    ajouteravis.cpp \
    midifieravis.cpp \
    ajoutersuggestion.cpp \
    ajouterreclamation.cpp \
    modifiersuggestion.cpp \
    modifierreclamation.cpp
    qdarkstyle/style.qrc

HEADERS += \
    login.h \
        mainwindow.h \
    avis.h \
    suggestion.h \
    reclamation.h \
    connection.h \
    ajouteravis.h \
    midifieravis.h \
    ajoutersuggestion.h \
    ajouterreclamation.h \
    modifiersuggestion.h \
    modifierreclamation.h

FORMS += \
    dialog.ui \
        mainwindow.ui \
    ajouteravis.ui \
    midifieravis.ui \
    ajoutersuggestion.ui \
    ajouterreclamation.ui \
    modifiersuggestion.ui \
    modifierreclamation.ui

RESOURCES += \
    sources.qrc
