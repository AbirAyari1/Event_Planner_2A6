#include "evenement.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

Evenement::Evenement()
{
    idevenement=0;
    nomevenement="";
    typeevenement="";
    prixevenement=0;
    tempsevenement=0;
}
Evenement::Evenement(int idevenement,QString nomevenement,QString typeevenement,int prixevenement, int tempsevenement)
{
    this->idevenement=idevenement;
    this->nomevenement=nomevenement;
    this->typeevenement=typeevenement;
    this->prixevenement=prixevenement;
    this->tempsevenement=tempsevenement;
}
QString  Evenement::get_nomevenement(){return nomevenement;}
QString  Evenement::get_typeevenement(){return typeevenement;}
int      Evenement::get_idevenement(){return idevenement;}
int      Evenement::get_prixevenement(){return prixevenement;}
int      Evenement::get_tempsevenement(){return tempsevenement;}

bool Evenement::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idevenement);
    QString res2= QString::number(prixevenement);
     QString res3= QString::number(tempsevenement);

     query.prepare("INSERT INTO EVENEMENT (IDEVENEMENT,NOMEVENEMENT,TYPEEVENEMENT,PRIXEVENEMENT,TEMPSEVENEMENT) "
                         "VALUES (:idevenement,:nomevenement,:typeevenement,:prixevenement,:tempsevenement)");

     query.bindValue(":idevenement", res);
     query.bindValue(":nomevenement",nomevenement);
     query.bindValue(":typeevenement",typeevenement);
     query.bindValue(":prixevenement",res2);
     query.bindValue(":tempsevenement",res3);
     return    query.exec();//execution de la requete
     //bind : ajout aveugle
}

QSqlQueryModel * Evenement::afficher()

{QSqlQueryModel * model= new QSqlQueryModel();//creation d'un pointeur

    model->setQuery("select * from EVENEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEVENEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMEVENEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEEVENEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXEVENEMENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEMPSEVENEMENT"));

  return model;
}

bool Evenement::supprimer(int idevenement)
{
QSqlQuery query;
QString res= QString::number(idevenement);
query.prepare("Delete from EVENEMENT where IDEVENEMENT = :idevenement ");
query.bindValue(":idevenement", res);//affectation et association des val
return    query.exec();
}

bool Evenement::modifier()
{QSqlQuery query;
    QString res= QString::number(idevenement);
    QString res2= QString::number(prixevenement);
    QString res3= QString::number(tempsevenement);
    query.prepare("UPDATE EVENEMENT set IDEVENEMENT=:idevenement,NOMEVENEMENT=:nomevenement,TYPEEVENEMENT=:typeevenement,PRIXEVENEMENT=:prixevenement,TEMPSEVENEMENT=:tempsevenement where IDEVENEMENT= :idevenement");
                  query.bindValue(":idevenement", res);
                   query.bindValue(":nomevenement",nomevenement);
                   query.bindValue(":typeevenement",typeevenement);
                   query.bindValue(":prixevenement",res2);
                       query.bindValue(":tempsevenement",res3);
        return    query.exec();
}

//QSqlQueryModel * Evenement::Rechercher(int idevenement)
//{

//    QSqlQueryModel *model=new QSqlQueryModel();
//    QSqlQuery query;
//    query.prepare("Select * from EVENEMENT where IDEVENEMENT =:idevenement");
//    query.bindValue(":idevenement",idevenement);
//    query.exec();
//    model->setQuery(query);
//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEVENEMENT"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMEVENEMENT"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEVENEMENT"));
//    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXEVENEMENT"));
//    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEMPSEVENEMENT"));
//        return model;
//   }
/*QSqlQueryModel * Evenement::recherche(QString info)
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("select ID from EVENEMENT where IDEVENEMENT='"+info+"'");
     query.exec();
     model->setQuery(query);
     return model;
 }*

/*QSqlQueryModel * Evenement::recherche(QString info)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= QString::number(idevenement);
    QString res1= QString::number(prixevenement);
    QString res2=QString::number(tempsevenement);


model->setQuery("select  id,nom,prenom,fonction,email,score from EMPLOYE where id ='"+info+"'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEVENEMENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMEVENEMENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEEVENEMENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXEVENEMENT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEMPSEVENEMENT"));




query.bindValue(":idevenement",res);
query.bindValue(":prixevenement",res);
query.bindvalue(":tempsevenement",res;

    return model;
}*/



//QSqlQueryModel * Evenement::afficher_tri()
//{QSqlQueryModel * model= new QSqlQueryModel();

//model->setQuery("select * from EVENEMENT order by IDEVENEMENT asc");
//model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEVENEMENT"));
//model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMEVENEMENT"));
//model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEEVENEMENT"));
//model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXEVENEMENT"));
//model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEMPSEVENEMENT"));
//    return model;
//}
