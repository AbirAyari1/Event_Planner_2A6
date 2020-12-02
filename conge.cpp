#include "conge.h"

// constructeur par defaut
Conge::Conge()
{ id=0;
  type="";
  debut="";
  fin="";
  idemp=0;
}

// constructeur parametre
Conge::Conge(int id,QString type,QString debut,QString fin,int idemp)

{ this->id=id; // int
  this->type=type;
  this->debut=debut;
  this->fin=fin;
  this->idemp=idemp; //int
}

//ajouter un conge
bool Conge::ajouter()
{QSqlQuery query;
 QString res1=QString::number(id);
 QString res2=QString::number(idemp);

query.prepare("INSERT INTO CONGE (ID,TYPE,DEBUT,FIN,IDEMP)"
              "VALUES (:id, :type, :debut, :fin, :idemp)");
query.bindValue(":id",res1);
query.bindValue(":type",type);
query.bindValue(":debut",debut);
query.bindValue(":fin",fin);
query.bindValue(":idemp",res2);
return query.exec(); //execution de la requete
//bind : ajout aveugle
}


// modifier un conge
bool Conge::modifier()
{ QSqlQuery query;
  QString res=QString::number(id);
  QString res2=QString::number(idemp);
  query.prepare("Update CONGE set TYPE=:type, DEBUT=:debut, FIN=:fin, IDEMP=:idemp where ID=:id");
  query.bindValue(":id",res);
  query.bindValue(":type",type);
  query.bindValue(":debut",debut);
  query.bindValue(":fin",fin);
  query.bindValue(":idemp",res2);
  return query.exec();
}

// afficher un conge
QSqlQueryModel * Conge::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel(); //creation d'un pointeur

  model->setQuery("select * from CONGE");

  return model;

}
//supprimer un conge
bool Conge::supprimer(int id)
{ QSqlQuery query;
  QString res=QString::number(id);
  query.prepare("Delete from CONGE where ID = :id ");
  query.bindValue(":id",res); //affectation et association des val
  return query.exec();}
