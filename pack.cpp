
#include "pack.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTableView>

Pack::Pack()

    {
        idpack=0;
        nompack="";
        typepack="";
    }
    Pack::Pack(int idpack,QString nompack,QString typepack, int ideve)
    {
        this->idpack=idpack;
        this->nompack=nompack;
        this->typepack=typepack;
        this->ideve=ideve;
    }
    QString  Pack::get_nompack(){return nompack;}
    QString  Pack::get_typepack(){return typepack;}
    int      Pack::get_idpack(){return idpack;}
    int      Pack::get_ideve(){return ideve;}

    bool Pack::ajouter()
    {
        QSqlQuery query;
        QString res= QString::number(idpack);
        QString res2= QString::number(ideve);

         query.prepare("INSERT INTO PACK (IDPACK,NOMPACK,TYPEPACK,IDEVE) "
                             "VALUES (:idpack,:nompack,:typepack,:ideve)");

         query.bindValue(":idpack", res);
         query.bindValue(":nompack",nompack);
         query.bindValue(":typepack",typepack);
         query.bindValue(":ideve",res2);
         return    query.exec();
    }

    QSqlQueryModel * Pack::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PACK");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPACK"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPACK"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEPACK"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDEVE"));
        return model;
    }

    bool Pack::supprimer(int idpack)
    {
    QSqlQuery query;
    QString res= QString::number(idpack);
    query.prepare("Delete from PACK where IDPACK = :idpack ");
    query.bindValue(":idpack", res);
    return    query.exec();
    }

    bool Pack::modifier()
    {
    {QSqlQuery query;
        QString res= QString::number(idpack);
        QString res2= QString::number(ideve);

             query.prepare("UPDATE PACK set IDPACK=:idpack,NOMPACK=:nompack,TYPEPACK=:typepack,IDEVE=:ideve where IDPACK= :idpack");
                       query.bindValue(":idpack", res);
                       query.bindValue(":nompack",nompack);
                       query.bindValue(":typepack",typepack);
                       query.bindValue(":ideve",res2);

            return    query.exec();
        }
    }

// QSqlQueryModel * Pack::Rechercher(int idpack)
//        {

//            QSqlQueryModel * model=new QSqlQueryModel();
//            QSqlQuery query;
//            query.prepare("Select * from PACK where IDPACK =:idpack");
//            query.bindValue(":idpack",idpack);
//            query.exec();
//            model->setQuery(query);
//            model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPACK"));
//            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPACK"));
//            model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEPACK"));
//                return model;
//           }


// QSqlQueryModel * Pack::afficher_tri()
//        {
//           QSqlQueryModel * model=new QSqlQueryModel();

//        model->setQuery("select * from PACK order by IDPACK asc");
//        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPACK"));
//        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPACK"));
//        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEPACK"));
//            return model;
//        }

