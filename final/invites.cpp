#include "invites.h"

#include <QSqlQuery>
#include <QMessageBox>

Invites::Invites()
{
    this->telInvite = "";
    this->nomInvite = "";
    this->prenomInvite = "";
    this->emailInvite = "";
}

Invites::Invites(QString tel, QString nom, QString prenom , QString email)
{
    this->telInvite = tel;
    this->nomInvite = nom;
    this->prenomInvite = prenom;
    this->emailInvite = email;
}

QString Invites::getTelInvite(){
    return this->telInvite;
}

QString Invites::getNomInvite(){
    return this->nomInvite;
}

QString Invites::getPrenomInvite(){
    return this->prenomInvite;
}

QString Invites::getEmailInvite(){
    return this->emailInvite;
}

bool Invites::ajouterInvite(){
    QSqlQuery query;

    query.prepare("insert into INVITE (NOM_INVITE,PRENOM_INVITE,TEL_INVITE, EMAIL_INVITE) values (:nom, :prenom, :tel, :email)" );

    query.bindValue(":nom", this->nomInvite);
    query.bindValue(":prenom", this->prenomInvite);
    query.bindValue(":tel", this->telInvite);
    query.bindValue(":email", this->emailInvite);

return query.exec();

}

QSqlQueryModel * Invites:: afficherInvite(){
QSqlQueryModel* model = new QSqlQueryModel();
model->setQuery("select * from INVITE");

model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("TEL"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("EMAIL"));



return model;
}


bool Invites :: modifierInvite(QString tel){
    QSqlQuery query;

    query.prepare("update INVITE set  NOM_INVITE =:nom, PRENOM_INVITE =:prenom,TEL_INVITE = :tel, EMAIL_INVITE = :email  where   TEL_INVITE = :tel");

    query.bindValue(":tel", tel);
    query.bindValue(":nom", this->nomInvite);
    query.bindValue(":prenom", this->prenomInvite);
    query.bindValue(":email",this->emailInvite);

    return query.exec();
}

bool Invites :: supprimerInvite(QString tel){
    QSqlQuery query;

    query.prepare("delete from INVITE where TEL_INVITE = :tel");
    query.bindValue(":tel", tel);

    return query.exec();

}


