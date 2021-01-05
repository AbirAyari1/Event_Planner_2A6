#include "commande.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

commande::commande()
{

    id=0;
    numero=0;
    quantite=0;
    produit="";
    prix_total=0.0;
    date="";


}
commande::commande(int id,int numero,int quantite,QString produit,float prix_total,QString date )
{
    this->id=id;
    this->numero=numero;
    this->quantite=quantite;
    this->produit=produit;
    this->prix_total=prix_total;
    this->date=date;

}

int commande:: get_id(){return id; }


bool commande:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id);
    QString res1= QString::number(numero);
    QString res2= QString::number(quantite);
    QString res3= QString::number(prix_total);
    query.prepare("INSERT INTO Commande (ID,NUMERO,QUANTITE,PRODUIT,PRIX_TOTAL,DATED) "
                        "VALUES ( :id,:numero,:quantite,:produit,:prix_total,:date)");
    query.bindValue(":id", res);
    query.bindValue(":numero", res1);
    query.bindValue(":quantite", res2);
    query.bindValue(":produit",produit);
    query.bindValue(":prix_total", res3);
    query.bindValue(":date",date);

    return    query.exec();
    }

QSqlQueryModel *commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE  order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATED"));

    return model;
}
bool commande::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from COMMANDE where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}
bool commande:: modifier(int id, int quantite, float prix_total, QString date)
{QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(quantite);
    QString res2= QString::number(prix_total);

         query.prepare("UPDATE COMMANDE set ID=:id, QUANTITE=:quantite,PRIX_TOTAL=:prix_total,DATED=:date where ID= :id ");

              query.bindValue(":id", res);
              query.bindValue(":quantite", res1);
              query.bindValue(":prix_total", res2);
              query.bindValue(":date",date);



        return    query.exec();

}


QSqlQueryModel * commande::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from COMMANDE where ID =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
   }

QSqlQueryModel * commande::afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE order by ID asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));

    return model;
}


QSqlQueryModel * commande::afficher_tri_numero()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE order by NUMERO asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));

    return model;
}

QSqlQueryModel * commande::afficher_tri_quantite()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE order by QUANTITE asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));

    return model;
}

QSqlQueryModel * commande::afficher_tri_produit()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE order by PRODUIT asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));

    return model;
}

QSqlQueryModel * commande::afficher_tri_prix_total()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE order by PRIX_TOTAL asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));

    return model;
}

QSqlQueryModel *commande::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM COMMANDE " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));


    return model;
}

