#include "salle.h"


salle::salle (int id,QString nom,QString lieu,QString type)
{
this ->nom=nom;
this->lieu=lieu;
this->type=type;
this->ID=id;
}



//Ajouter
bool salle :: ajouter()
{
//réquette insert
  QSqlQuery query;
  QString res = QString::number(ID);
  query.prepare("INSERT INTO salle (id, nom, type, lieu) "
                "VALUES (:id, :nom, :type, :lieu)");
  query.bindValue(":id", res);
  query.bindValue(":nom",nom);
  query.bindValue(":type", type);
  query.bindValue(":lieu", lieu);
  return query.exec();

}


//Afficher
  QSqlQueryModel * salle::afficher()
  {
   QSqlQueryModel *model=new QSqlQueryModel();

   model->setQuery("select * from salle");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieu"));
     return model;
  }



//Supprimer
  bool salle::supprimer(int id)
  {
      QSqlQuery query;
      QString res=QString::number(id);
      query.prepare("Delete from salle where ID=:id");
      query.bindValue(":id",res);
      return query.exec();

  }



  //modifier
  bool salle::modifier(int id,QString nom,QString lieu,QString type)
  {

      QSqlQuery query;
      query.prepare("update salle set  nom = :nom , type = :type , lieu =:lieu ,id =:id where id = :id ");
      query.bindValue(":nom",nom);
      query.bindValue(":type", type);
      query.bindValue(":lieu", lieu);
      query.bindValue(":id", id);
      return query.exec();
  }

