#include "avis.h"
#include<qDebug>
#include<QString>
#include<QSqlError>
#include<iostream>
#include<ostream>
#include"connection.h"

avis::avis(QString id_client,QString nom,QString prenom,QString email)

{   this->id_client=id_client;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;

}
bool avis::ajouter()
{

    QSqlQuery query;
                     query.prepare("INSERT INTO AVIS VALUES (?,?,?,?)");
                     query.addBindValue(this->id_client);
                     query.addBindValue(this->nom);
                     query.addBindValue(this->prenom);
                     query.addBindValue(this->email);

       return query.exec();

}
bool avis :: supprimer(QString nom)
{
    QSqlQuery qry ;
    qry.prepare("delete from AVIS where NOM=?");
    qry.addBindValue(nom);
    return qry.exec();

}
QSqlQueryModel* avis ::affichage(QString a)
{
    if(a=="Nom")
       { QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *qr=new QSqlQuery();
        qr->prepare("SELECT * from AVIS ORDER BY NOM ASC");  //parcours table
       qr->exec();
       modal->setQuery(*qr);
           return modal;
    }
        else
         {   QSqlQueryModel * modal=new QSqlQueryModel();
            QSqlQuery *qr=new QSqlQuery();
            qr->prepare("SELECT * from AVIS ORDER BY ID_CLIENT ASC");  //parcours table
           qr->exec();
            modal->setQuery(*qr);
            return modal;
    }

}

    bool avis::modifier(QString a,QString b,QString c,QString d)
    {
     QSqlQuery q;
    //Mettre à jour le nom

     q.prepare("UPDATE AVIS set NOM=:NOM, PRENOM=:PRENOM,EMAIL=:EMAIL where ID_CLIENT='"+a+"'");
            q.bindValue(":NOM",b);
            q.bindValue(":PRENOM",c);
            q.bindValue(":EMAIL",d);
            return q.exec();

    }
QSqlQueryModel* avis::recherche(QString b)
{
    QSqlQueryModel * modal=new QSqlQueryModel();
            QSqlQuery *qr=new QSqlQuery();
            qr->prepare("SELECT * from AVIS where NOM LIKE '%"+b+"%' or PRENOM LIKE '%"+b+"%' or EMAIL LIKE '%"+b+"%' or ID_CLIENT LIKE '%"+b+"%'");  //parcours table
            qr->exec();
            modal->setQuery(*qr);
            return modal;
}
