#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTableView>

class Evenement
{
public:
    Evenement();
    Evenement(int, QString, QString);
    QString get_nomevenement();
    int get_idevenement();
    QString get_typeevenement();
    int get_prixevenement();
    int get_tempsevenement();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,int);
    QSqlQueryModel * Rechercher(int );
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * afficher_stat();



private:
    QString nomevenement, typeevenement;
    int idevenement, prixevenement, tempsevenement;
};

#endif // EVENEMENT_H
