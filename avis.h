#ifndef AVIS_H
#define AVIS_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QAbstractItemModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>



class avis
{
private:
    QString id_client;
    QString nom;
    QString prenom;
    QString email;
public:
    avis(){};
    avis(QString id_client,QString nom,QString prenom,QString email);
    void set_id_client(QString id_client){this->id_client=id_client;}
    void set_nom(QString nom){this->nom=nom;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_email(QString email){this->email=email;}
    QString get_id_client() {return id_client;}
     QString get_nom(){return nom;}
     QString get_prenom(){return prenom;}
     QString get_email(){return email;}
    bool ajouter();
    bool supprimer(QString nom);
    QSqlQueryModel* affichage(QString);
    bool modifier(QString,QString,QString,QString);
    QSqlQueryModel* recherche(QString);

};


#endif // AVIS_H
