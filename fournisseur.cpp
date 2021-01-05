#include "fournisseur.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

fournisseur::fournisseur()
{
    id=0;
    num_telephone=0;
    nom="";
    prenom="";
    email="";

}
fournisseur::fournisseur(int id,QString nom,QString prenom, int num_telephone, QString email )
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->num_telephone=num_telephone;
    this->email=email;
}

int fournisseur:: get_id(){return id; }


bool fournisseur:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id);
        QString res1= QString::number(num_telephone);
    query.prepare("INSERT INTO Fournisseur (ID,NOM,PRENOM,NUM_TELEPHONE,EMAIL) "
                        "VALUES ( :id,:nom,:prenom,:num_telephone,:email)");
    query.bindValue(":id", res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num_telephone", res1);
    query.bindValue(":email",email);


    return    query.exec();
    }

QSqlQueryModel *fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR  order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_TELEPHONE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));


    return model;
}
bool fournisseur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from FOURNISSEUR where ID = :id ");
    query.bindValue(":id", id);
    return    query.exec();
}

bool fournisseur:: modifier(int id ,int num_telephone )
{QSqlQuery query;
    QString res= QString::number(num_telephone);
    QString res2= QString::number(id);

         query.prepare("UPDATE FOURNISSEUR set ID=:id,NUM_TELEPHONE=:num_telephone where ID= :id ");
         query.bindValue(":id", res2);
         query.bindValue(":num_telephone", res);

        return    query.exec();

}

QSqlQueryModel * fournisseur::afficher_email()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select EMAIL from FOURNISSEUR   ");
    return model;
}


QSqlQueryModel * fournisseur::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from FOURNISSEUR where ID =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
   }


QSqlQueryModel * fournisseur::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}


bool fournisseur::testemail(QString email){
    int test=0;
    for(int i = 0; i < email.size(); i++) {
if(email[i]=="@")
{test++;

}}
    for(int i = 0; i < email.size(); i++) {
if((test==1)&&(email[i]=="."))
{if(email.size()>i+1)
    return true;
}}
return false;}

QSqlQueryModel *fournisseur::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM FOURNISSEUR " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));


    return model;
}

