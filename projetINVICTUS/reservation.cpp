#include "reservation.h"


reservation::reservation( QString nom_client ,QString prenom_client, QString nom_salle,QString date_reservation,int nb_heure,int id)
{
this->ID=id;
this ->nom_client=nom_client;
this->prenom_client=prenom_client;
this->nom_salle=nom_salle;
this->nb_heure=nb_heure;
this->date_reservation=date_reservation;


}


// ajouter
bool reservation :: ajouter()
{
//réquette insert
  QSqlQuery query;
  QString res = QString::number(ID);
  query.prepare("INSERT INTO reservation (id, nom_client, prenom_client, nom_salle,date_reservation,nb_heure) "
                "VALUES (:id, :nom_client, :prenom_client , :nom_salle, :date_reservation , :nb_heure)");
  query.bindValue(":id", res);
  query.bindValue(":nom_client",nom_client);
  query.bindValue(":prenom_client", prenom_client);
  query.bindValue(":nom_salle", nom_salle);
  query.bindValue(":date_reservation", date_reservation);
  query.bindValue(":nb_heure", nb_heure);
  return query.exec();

}




//Afficher
  QSqlQueryModel * reservation::afficher()
  {
   QSqlQueryModel *model=new QSqlQueryModel();

   model->setQuery("select * from reservation");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_client"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_client"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_reservation"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("nb_heure"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom_salle"));
     return model;
  }



  //Supprimer
    bool reservation::supprimer(int id)
    {
        QSqlQuery query;
        QString res=QString::number(id);
        query.prepare("Delete from reservation where ID=:id");
        query.bindValue(":id",res);
        return query.exec();
    }



    //modifier
    bool reservation::modifier(QString nom_client, QString prenom_client, QString date_reservation, QString nom_salle, int nb_heure ,int id)
        {
            QSqlQuery query;
            query.prepare("update reservation set  nom_client = :nom_client , prenom_client = :prenom_client , date_reservation =:date_reservation , nom_salle =:nom_salle , nb_heure = :nb_heure ,id =:id where id = :id ");
            query.bindValue(":nom_client",nom_client);
            query.bindValue(":prenom_client", prenom_client);
            query.bindValue("date_reservation", date_reservation);
            query.bindValue(":nom_salle",nom_salle);
            query.bindValue(":nb_heure", nb_heure);
            query.bindValue(":id", id);
            return query.exec();
        }
