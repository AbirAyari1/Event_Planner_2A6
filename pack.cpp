#include "pack.h"

Pack::Pack()

    {
        idpack=0;
        nompack="";
        typepack="";
    }
    Pack::Pack(int idpack,QString nompack,QString typepack)
    {
        this->idpack=idpack;
        this->nompack=nompack;
        this->typepack=typepack;
    }
    QString  Pack::get_nompack(){return nompack;}
    QString  Pack::get_typepack(){return typepack;}
    int      Pack::get_idpack(){return idpack;}

    bool Pack::ajouter()
    {
        QSqlQuery query;
        QString res= QString::number(idpack);

         query.prepare("INSERT INTO EVENEMENT (IDPACK,NOMPACK,TYPEPACK) "
                             "VALUES (:idpack,:nompack,:typepack)");

         query.bindValue(":idevenement", res);
         query.bindValue(":nompack",nompack);
         query.bindValue(":typepack",typepack);
         return    query.exec();
    }

    QSqlQueryModel * Pack::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PACK");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPACK"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPACK"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEPACK"));

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

    bool Pack:: modifier(int idpack,QString nompack,QString typepack)
    {
    {QSqlQuery query;
        QString res= QString::number(idevenement);

             query.prepare("UPDATE PACK set IDPACK=:idpack,NOMPACK=:nompack,TYPEPACK=:typepack where IDPACK= :idpack");
                       query.bindValue(":idpack", res);
                       query.bindValue(":nompack",nompack);
                       query.bindValue(":typepack",typepack);

            return    query.exec();
    }

        QSqlQueryModel * Pack::Rechercher(int idpack)
        {

            QSqlQueryModel *model=new QSqlQueryModel();
            QSqlQuery query;
            query.prepare("Select * from PACK where IDPACK =:idpack");
            query.bindValue(":idpack",idpack);
            query.exec();
            model->setQuery(query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPACK"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPACK"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEPACK"));
                return model;
           }


        QSqlQueryModel * Pack::afficher_tri()
        {QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from PACK order by IDEVENEMENT asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPACK"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPACK"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEPACK"));
            return model;
        }

