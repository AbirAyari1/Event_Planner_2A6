#include "table.h"
#include <QMessageBox>
#include <QSqlQuery>

Table::Table()
{
    this->nomTable = "";
    this->typeTable = "";
    this->nbPlace = 0;
}

Table::Table(QString nomTable, QString typeTable, int nbPlace){
    this->nomTable = nomTable;
    this->typeTable = typeTable;
    this->nbPlace = nbPlace;
}

QString Table::getNomTable(){
    return this->nomTable;
}


QString Table::getTypeTable(){
    return this->typeTable;
}

bool Table::ajouterTable(){

    QSqlQuery query;
    query.prepare("insert into TABLE_EVENT (NOM_TABLE, TYPE_TABLE, NOMBRE_PLACE) values (:nom, :type, :nbPlace) ");

    query.bindValue(":nom", this->nomTable);
    query.bindValue(":type", this->typeTable);
    query.bindValue(":nbPlace", this->nbPlace);

    return query.exec();
}

QSqlQueryModel * Table:: afficherTable(){
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("select * from TABLE_EVENT");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOMBRE PLACE"));

    return model;
}

bool Table::modifierTable(QString nomTableMod){
    QSqlQuery query;

    query.prepare("update TABLE_EVENT set NOM_TABLE =:nom, TYPE_TABLE =:typeTable, NOMBRE_PLACE =:nbPlace where NOM_TABLE =:nom");

    query.bindValue(":nom", nomTableMod);
    query.bindValue(":typeTable", this->typeTable);
    query.bindValue(":nbPlace", this->nbPlace);

    return query.exec();
}

bool Table::supprimerTable(QString nomTableSuppr){
    QSqlQuery query;

    query.prepare("delete from TABLE_EVENT where NOM_TABLE =:nom");
    query.bindValue(":nom", nomTableSuppr);

    return query.exec();
}
