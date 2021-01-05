#ifndef TABLE_H
#define TABLE_H
#include <QSqlQueryModel>
#include <QString>


class Table
{

private:
    QString nomTable, typeTable;
    int nbPlace;

public:
    Table();
    Table(QString,QString,int);
    QString getNomTable();
    QString getTypeTable();
    bool ajouterTable();
    QSqlQueryModel * afficherTable();
    bool supprimerTable(QString);
    bool modifierTable(QString);
};

#endif // TABLE_H
