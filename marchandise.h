#ifndef MARCHANDISE_H
#define MARCHANDISE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class marchandise
{
public:
    marchandise();
    marchandise(QString,int,float,int,QString);
    int get_quantite();
    float get_prix();
    QString get_type();
    int get_numero();
    QString get_produit();

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_type();
    QSqlQueryModel * afficher_numero();
    QSqlQueryModel * afficher_produit();
    bool supprimer(QString);
    QSqlQueryModel *rechercher_type(QSqlQuery);
    bool modifier(QString,int,float,int,QString);
    QSqlQueryModel * rechercher(QString );


    QSqlQueryModel * afficher_tri_type();
    QSqlQueryModel * afficher_tri_quantite();
    QSqlQueryModel * afficher_tri_prix();
    QSqlQueryModel * afficher_tri_numero();
    QSqlQueryModel * afficher_tri_produit();

    QSqlQueryModel *displayClause(QString cls);

private:

QString type;
int quantite;
float prix;
int numero;
QString produit;




};

#endif // MARCHANDISE_H
