#ifndef PACK_H
#define PACK_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTableView>

class Pack
{
public:
    Pack();
    Pack(int, QString, QString);
    QString get_nompack();
    int get_idpack();
    QString get_typepack();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,int);
    QSqlQueryModel * Rechercher(int );
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * afficher_stat();



private:
    QString nompack, typepack;
    int idpack;
};


#endif // PACK_H
