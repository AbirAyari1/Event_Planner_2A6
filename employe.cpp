#include "employe.h"


Employe::Employe()
{id=0;
 nom="";
 prenom="";
 email="";
 fonction="";
 score=0;
}


Employe::Employe(int id,QString nom,QString prenom,QString email,QString fonction,int score)

{ this->id=id; // int
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;
  this->fonction=fonction;
  this->score=score; // int

}


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



QSqlQueryModel * Employe::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel(); //creation d'un pointeur

  model->setQuery("select * from EMPLOYE");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("FONCTION"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("SCORE"));
  return model;

}

bool Employe::supprimer(int id)
{ QSqlQuery query;
  QString res=QString::number(id);
  query.prepare("Delete from employes where ID = :id ");
  query.bindValue(":id",res); //affectation et association des val
  return query.exec();}


bool Employe::modifier(int id)
{ QSqlQuery query;
  QString res=QString::number(id);
  QString res1=QString::number(score);
  query.prepare("Update Employe set ID=:id, NOM=:nom, PRENOM=:prenom, EMAIL=:email, FONCTION=:fonction, SCORE=:score");
  query.bindValue(":id",res);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":email",email);
  query.bindValue(":fonction",fonction);
  query.bindValue(":score",res1);
  return query.exec();
}









