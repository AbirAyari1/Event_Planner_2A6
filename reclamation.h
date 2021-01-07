#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QAbstractItemModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include"connection.h"

class reclamation
{
public:
    reclamation(){};
    reclamation(QString id_client,QString id_res,QString date_de_res,QString typer);
    bool ajouter();
    bool modifier(QString,QString,QString,QString);
    QSqlQueryModel* affichage(QString);
    bool supprimer(QString id_res);
    QSqlQueryModel* recherchereclamation(QString);

void creerpdf();
private:
    QString id_client,id_res;


   QString date_de_res;
   QString typer;
};

#endif // RECLAMATION_H
