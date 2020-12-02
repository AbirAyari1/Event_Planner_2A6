#include "employe.h"

//constructeur par defaut
Employe::Employe()
{id=0;
 nom="";
 prenom="";
 email="";
 fonction="";
 score=0;
}

//constructeur parametre
Employe::Employe(int id,QString nom,QString prenom,QString email,QString fonction,int score)

{ this->id=id; // int
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;
  this->fonction=fonction;
  this->score=score; // int

}

//ajouter employe
bool Employe::ajouter()
{QSqlQuery query;
 QString res1=QString::number(id);
 QString res2=QString::number(score);

query.prepare("INSERT INTO EMPLOYE (ID,NOM,PRENOM,EMAIL,FONCTION,SCORE)"
              "VALUES (:id, :nom, :prenom, :email, :fonction, :score)");
query.bindValue(":id",res1);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":email",email);
query.bindValue(":fonction",fonction);
query.bindValue(":score",res2);
return query.exec(); //execution de la requete
//bind : ajout aveugle
}


//afficher employe
QSqlQueryModel * Employe::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel(); //creation d'un pointeur

  model->setQuery("select * from EMPLOYE");

  return model;

}

//supression employe
bool Employe::supprimer(int id)
{ QSqlQuery query;
  QString res=QString::number(id);
  query.prepare("Delete from EMPLOYE where ID = :id ");
  query.bindValue(":id",res); //affectation et association des val
  return query.exec();}

//modification employe
bool Employe::modifier()
{ QSqlQuery query;
  QString res=QString::number(id);
  QString res1=QString::number(score);
  query.prepare("Update Employe set ID=:id, NOM=:nom, PRENOM=:prenom, EMAIL=:email, FONCTION=:fonction, SCORE=:score where ID=:id");
  query.bindValue(":id",res);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":email",email);
  query.bindValue(":fonction",fonction);
  query.bindValue(":score",res1);
  return query.exec();
}








