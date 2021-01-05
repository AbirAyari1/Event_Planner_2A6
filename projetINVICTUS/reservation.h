#ifndef RESERVATION_H
#define RESERVATION_H
#include <qstring.h>
#include <qsqlquerymodel.h>
#include <QSqlQuery>


class reservation
{
    QString nom_client, prenom_client, nom_salle,date_reservation ;
    int ID ,nb_heure;
public:
    //construscteurs
    reservation(){}
    reservation( QString ,QString, QString,QString,int,int);



    //Getters
    QString getnom_client() {return nom_client;}
    QString getprenom_client() {return prenom_client;}
    QString getdate_reservation() {return date_reservation;}
    QString getnom() {return nom_salle;}
    int getid(){return ID;}
    int getnb_heure(){return nb_heure;}

    //setters
    void setnom_client(QString n){nom_salle=n;}
    void setprenom_client(QString t){nom_client=t;}
    void setnom(QString l){nom_salle=l;}
    void setdate_reservation(QString r){date_reservation=r;}
    void setnb_heure(int b){this->nb_heure=b;}
    void setid(int id){this->ID=id;}


    //fonctionnalités de base relatives à l'entité salle
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int);
    bool modifier( QString ,QString, QString,QString,int,int);
        ~reservation(){}

};

#endif // RESERVATION_H
