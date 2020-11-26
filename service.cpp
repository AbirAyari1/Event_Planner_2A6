#include "service.h"

service::service()
{
    idservice=0;
    nomservice="";
    cathservice="";
    prixservice=0;
}
service::service(int idservice,QString nomservice,QString cathservice,int prixservice)
{
    this->idservice=idservice;
    this->nomservice=nomservice;
    this->cathservice=cathservice;
    this->prixservice=prixservice;
}
QString  service::get_nomservice(){return nomservice;}
QString  service::get_cathservice(){return cathservice;}
int      service::get_idservice(){return idservice;}
int      service::get_prixservice(){return prixservice;}


bool service::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idservice);
    QString res2= QString::number(prixservice);


     query.prepare("INSERT INTO SERVICE (IDSERVICE,NOMSERVICE,CATHSERVICE,PRIXSERVICE) "
                         "VALUES (:idservice,:nomservice,:cathservice,:prixservice)");

     query.bindValue(":idservice", res);
     query.bindValue(":nomservice",nomservice);
     query.bindValue(":cathservice",cathservice);
     query.bindValue(":prixservice",res2);
     return    query.exec();
}

QSqlQueryModel * Pack::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SERVICE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDSERVICE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSERVICE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATHSERVICE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXSERVICE"));

    return model;
}


bool service::supprimer(int idservice)
{
QSqlQuery query;
QString res= QString::number(idservice);
query.prepare("Delete from SERVICE where IDSERVICE = :idservice ");
query.bindValue(":idservice", res);
return    query.exec();
}

bool service:: modifier(int idservice,QString nomservice,QString cathservice,int prixservice)
{QSqlQuery query;
    QString res= QString::number(idservice);
    QString res2= QString::number(prixservice);


         query.prepare("UPDATE SERVICE set IDSERVICE=:idservice,NOMSERVICE=:nomservice,CATHSERVICE=:cathservice,PRIXSERVICE=:prixservice where IDSERVICE= :idservice");
                   query.bindValue(":idservice", res);
                   query.bindValue(":nomevenement",nomservice);
                   query.bindValue(":typeevenement",cathservice);
                   query.bindValue(":prixevenement",res2);
        return    query.exec();
}

QSqlQueryModel * service::Rechercher(int idservice)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from SERVICE where IDSERVICE =:idservice");
    query.bindValue(":idservice",idservice);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDSERVICE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSERVICE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATHSERVICE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXSERVICE"));
        return model;
   }

QSqlQueryModel * service::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SERVICE order by IDSERVICE asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDSERVICE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMSERVICE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATHSERVICE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXSERVICE"));

    return model;
}
