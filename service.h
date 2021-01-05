#ifndef SERVICE_H
#define SERVICE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTableView>

class service
{
public:
    service();
    service(int, QString, QString,int);

    QString nomservice, cathservice;
    int idservice, prixservice;

    //GETTERS
    QString get_nomservice();
    int get_idservice();
    QString get_cathservice();
    int get_prixservice();

    //SETTERS
    void set_nomservice(QString nomservice){this->nomservice=nomservice;}
    void set_idservice(int idservice){this->idservice=idservice;}
    void set_cathservice(QString cathservice){this->cathservice=cathservice;}
    void set_prixservice(int prixservice){this->prixservice=prixservice;}


    //CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * Rechercher(int );
    QSqlQueryModel * afficher_tri();






};

#endif // SERVICE_H
