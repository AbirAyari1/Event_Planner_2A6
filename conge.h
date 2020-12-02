#ifndef CONGE_H
#define CONGE_H
#include<QSqlQuery> /*provides a means of executing and manipulating SQL statements*/
#include<QSqlQueryModel> /*provides a read-only data model for SQL result sets. */

class Conge
{
int id,idemp;
QString type,debut,fin;



public:
//Constructeurs
Conge();
Conge(int,QString,QString,QString,int);
//Getters

int getId(){return id;}
QString getType(){return type;}
QString getDebut(){return debut;}
QString getFin(){return fin;}
int getIdemp(){return idemp;}


//Setters

void setId(int id){this->id=id;}
void setType(QString type){this->type=type;}
void setDebut(QString debut){this->debut=debut;}
void setFin(QString fin){this->fin=fin;}
void setIdemp(int idemp){this->idemp=idemp;}


//CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier ();


};

#endif // CONGE_H
