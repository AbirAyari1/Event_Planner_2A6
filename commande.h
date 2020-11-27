#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class commande
{
public:
    commande();
    commande(int,int,int,QString,float,QString);
    int get_id();
    int get_numero();
    int get_quantite();
    QString get_produit();
    float get_prix_total();
    QString get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,float,QString);
    QSqlQueryModel * rechercher(int );
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_numero();
    QSqlQueryModel * afficher_tri_quantite();
    QSqlQueryModel * afficher_tri_produit();
    QSqlQueryModel * afficher_tri_prix_total();

    QSqlQueryModel *displayClause(QString cls);

private:


int id;
int numero;
int quantite;
QString produit;
float prix_total;
QString date;



};

#endif // COMMANDE_H
