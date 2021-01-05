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

    QString nompack, typepack;
    int idpack;

    //GETTERS
    QString get_nompack();
    int get_idpack();
    QString get_typepack();


    //SETTERS
    void set_nompack(QString nompack){this->nompack=nompack;}
    void get_idpack(int idpack){this->idpack=idpack;}
    void get_typepack(QString typepack){this->typepack=typepack;}

    //CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * Rechercher(int);
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * afficher_stat();




};


#endif // PACK_H
