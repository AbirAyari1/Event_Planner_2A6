#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include<QSqlQuery> /*provides a means of executing and manipulating SQL statements*/
#include<QSqlQueryModel> /*provides a read-only data model for SQL result sets. */


class Employe
{ QString nom,prenom,email,fonction;
  int score,id;


public:
    //Constructeurs
    Employe();
    Employe(int,QString,QString,QString,QString,int);

    //Getters

    int getId(){return id;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getEmail(){return email;}
    QString getFonction(){return fonction;}
    int getScore(){return score;}

    //Setters

    void setId(int id){this->id=id;}
    void setNom(QString nom){this->nom=nom;}
    void setPrenom(QString prenom){this->prenom=prenom;}
    void setEmail(QString email){this->email=email;}
    void setFonction(QString fonction){this->fonction=fonction;}
    void setScore(int score){this->score=score;}

    //CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (int);





};

#endif // EMPLOYE_H
