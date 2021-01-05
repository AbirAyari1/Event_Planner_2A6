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
    Evenement(int, QString, QString,int,int);

    QString nomevenement, typeevenement;
    int idevenement, prixevenement, tempsevenement;

    //Getters
    QString get_nomevenement();
    int get_idevenement();
    QString get_typeevenement();
    int get_prixevenement();
    int get_tempsevenement();


    //Setters
    void set_nomevenement(QString nomevenement){this->nomevenement=nomevenement;}
    void set_idevenement(int idevenement){this->idevenement=idevenement;}
    void set_typeevenement(QString typeevenement){this->typeevenement=typeevenement;}
    void set_prixevenement(int prixevenement){this->prixevenement=prixevenement;}
    void set_tempsevenement(int tempsevenement){this->tempsevenement=tempsevenement;}


    //CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * Rechercher(int );
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * afficher_stat();



};

#endif // EVENEMENT_H
