#include "marchandise.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

marchandise::marchandise()
{

    type="";
    quantite=0;
    prix=0.0;
    numero=0;
    produit="";


}
marchandise::marchandise(QString type,int quantite,float prix,int numero,QString produit)
{
    this->type=type;
    this->quantite=quantite;
    this->prix=prix;
    this->numero=numero;
    this->produit=produit;



}

QString marchandise:: get_type(){return type; }


bool marchandise:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(quantite);
    QString res1= QString::number(prix);
    QString res2= QString::number(numero);
    query.prepare("INSERT INTO MARCHANDISE (TYPE,QUANTITE,PRIX,NUMERO,PRODUIT) "
                        "VALUES ( :type,:quantite,:prix, :numero, :produit)");
    query.bindValue(":type",type);
    query.bindValue(":quantite", res);
    query.bindValue(":prix", res1);
    query.bindValue(":numero", res2);
    query.bindValue(":produit",produit);


    return    query.exec();
    }

QSqlQueryModel *marchandise::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MARCHANDISE  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRODUIT"));

    return model;
}

QSqlQueryModel * marchandise:: afficher_type(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select TYPE from MARCHANDISE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
     return model;
    }

QSqlQueryModel * marchandise:: afficher_numero(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select NUMERO from MARCHANDISE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
     return model;
    }

QSqlQueryModel * marchandise:: afficher_produit(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select PRODUIT from MARCHANDISE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRODUIT"));
     return model;
    }




bool marchandise::supprimer(QString type)
{
    QSqlQuery query;
    QString res= QString(type);
    query.prepare("Delete from MARCHANDISE where TYPE = :type ");
    query.bindValue(":type", res);
    return    query.exec();
}
bool marchandise:: modifier(QString type, int quantite, float prix, int numero, QString produit )
{QSqlQuery query;
    QString res= QString::number(quantite);
    QString res1= QString::number(prix);
    QString res2= QString::number(numero);


              query.prepare("UPDATE MARCHANDISE set TYPE=:type, QUANTITE=:quantite,PRIX=:prix, NUMERO=:numero, PRODUIT=:produit where TYPE= :type ");
              query.bindValue(":type",type);
              query.bindValue(":quantite", res);
              query.bindValue(":prix", res1);
              query.bindValue(":numero", res2);
              query.bindValue(":produit",produit);



        return    query.exec();

}


QSqlQueryModel * marchandise::rechercher(QString type)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from MARCHANDISE where TYPE =:type");
    query.bindValue(":type",type);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));

        return model;
   }

QSqlQueryModel *   marchandise::rechercher_type(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}



QSqlQueryModel * marchandise::afficher_tri_type()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MARCHANDISE order by TYPE asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRODUIT"));


    return model;
}

QSqlQueryModel * marchandise::afficher_tri_quantite()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MARCHANDISE order by QUANTITE asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRODUIT"));


    return model;
}

QSqlQueryModel * marchandise::afficher_tri_prix()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MARCHANDISE order by PRIX asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRODUIT"));


    return model;
}


QSqlQueryModel * marchandise::afficher_tri_numero()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MARCHANDISE order by NUMERO asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRODUIT"));


    return model;
}


QSqlQueryModel * marchandise::afficher_tri_produit()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MARCHANDISE order by PRODUIT asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRODUIT"));


    return model;
}


QSqlQueryModel *marchandise::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM MARCHANDISE " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRODUIT"));


    return model;
}








