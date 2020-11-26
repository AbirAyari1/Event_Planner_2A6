#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "categorie.h"

categorie::categorie(){
    typeCategorie = "";
}

categorie::categorie(QString typeCategorie){
    this->typeCategorie = typeCategorie;
}

QString categorie::getType(){
    return typeCategorie;
}

bool categorie::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO categorie VALUES (:typeCategorie)");
    query.bindValue(":typeCategorie", typeCategorie);
    return query.exec();
}

QSqlQueryModel *  categorie::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM categorie");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type de Categorie"));
    return model;
}

bool categorie::supprimer(QString typeCategorie){
    QSqlQuery query;
    query.prepare("DELETE FROM categorie WHERE type = :typeCategorie");
    query.bindValue(":typeCategorie", typeCategorie);
    return query.exec();
}
