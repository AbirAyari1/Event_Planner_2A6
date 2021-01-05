#ifndef SALLE_H
#define SALLE_H
#include <qstring.h>
#include <qsqlquerymodel.h>
#include <QSqlQuery>


class salle
{
    QString nom, type, lieu ;
    int ID ;
public:
    //construscteurs
    salle(){}
    salle(int, QString ,QString, QString);



    //Getters
    QString getnom() {return nom;}
    QString gettype() {return type;}
    QString getlieu() {return lieu;}
    int getid(){return ID;}

    //setters
    void setnom(QString n){nom=n;}
    void settype(QString t){type=t;}
    void setlieu(QString l){lieu=l;}
    void setid(int id){this->ID=id;}



    //fonctionnalités de base relatives à l'entité salle
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier(int, QString ,QString, QString);
        ~salle(){}


};


#endif // SALLE_H
