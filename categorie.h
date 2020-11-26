#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class categorie{
    public:
        categorie();
        categorie(QString);
        QString getType();
        bool ajouter();
        bool supprimer(QString);
        QSqlQueryModel * afficher();
    private:
        QString typeCategorie;
};

#endif // CATEGORIE_H
