#include "invitation.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>

Invitation::Invitation()
{
    this->nomInv = "";
    this->idTable = 0;
    this->positionInviteTable = 0;
}

Invitation::Invitation(QString idInvite, int idTable, int positionInviteTable){
    this->nomInv = idInvite;
    this->idTable = idTable;
    this->positionInviteTable = positionInviteTable;
}

int Invitation::getIdITable(){
    return this->idTable;
}

QString Invitation::getNomInvite(){
    return this->nomInv;
}

int Invitation::getPositionInviteTable(){
    return this->positionInviteTable;
}

