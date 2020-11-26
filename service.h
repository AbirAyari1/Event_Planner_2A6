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
    service(int, QString, QString);
    QString get_nomservice();
    int get_idservice();
    QString get_cathservice();
    int get_prixservice();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int);
    QSqlQueryModel * Rechercher(int );
    QSqlQueryModel * afficher_tri();




private:
    QString nomservice, cathservice;
    int idservice, prixservice;
};

#endif // SERVICE_H
