#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString,QString,int,QString);
    int get_id();
    int get_num_telephone();
    QString get_nom();
    QString get_prenom();
    QString get_email();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * afficher_email();
     bool testemail(QString);

    bool modifier(int,int);
    QSqlQueryModel * rechercher(int );
    QSqlQueryModel * afficher_tri();

    QSqlQueryModel *displayClause(QString cls);

private:


int id;
int num_telephone;
QString nom;
QString prenom;
QString email;




};

#endif // FOURNISSEUR_H
