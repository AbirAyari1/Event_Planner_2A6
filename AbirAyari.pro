QT       += core gui network sql multimedia serialport texttospeech printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../../Downloads/final2/final/dialogeemmanuel.cpp \
    ../../../../Downloads/final2/final/dialogemmanuel.cpp \
    ../../../../Downloads/final2/final/invitation.cpp \
    ../../../../Downloads/final2/final/invites.cpp \
    ../../../../Downloads/final2/final/table.cpp \
    accesscard.cpp \
    client.cpp \
    commande.cpp \
    conge.cpp \
    connection.cpp \
    connecxion.cpp \
    dialogahmed.cpp \
    dialogamen.cpp \
    employe.cpp \
    evenement.cpp \
    exportexcelobject.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp \
    marchandise.cpp \
    notification.cpp \
    pack.cpp \
    peermanager.cpp \
    projetINVICTUS/dialogasma.cpp \
    projetINVICTUS/reservation.cpp \
    projetINVICTUS/salle.cpp \
    rh.cpp \
    server.cpp \
    service.cpp \
    smtp.cpp

HEADERS += \
    ../../../../Downloads/final2/final/dialogeemmanuel.h \
    ../../../../Downloads/final2/final/dialogemmanuel.h \
    ../../../../Downloads/final2/final/invitation.h \
    ../../../../Downloads/final2/final/invites.h \
    ../../../../Downloads/final2/final/table.h \
    accesscard.h \
    client.h \
    commande.h \
    conge.h \
    connection.h \
    connecxion.h \
    dialogahmed.h \
    dialogamen.h \
    employe.h \
    evenement.h \
    exportexcelobject.h \
    fournisseur.h \
    mainwindow.h \
    marchandise.h \
    notification.h \
    pack.h \
    peermanager.h \
    projetINVICTUS/dialogasma.h \
    projetINVICTUS/reservation.h \
    projetINVICTUS/salle.h \
    rh.h \
    server.h \
    service.h \
    smtp.h

FORMS += \
    ../../../../Downloads/final2/final/dialogeemmanuel.ui \
    dialogahmed.ui \
    dialogamen.ui \
    mainwindow.ui \
    projetINVICTUS/dialogasma.ui \
    rh.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../../Downloads/final2/final/ressources.qrc \
    background.qrc \

