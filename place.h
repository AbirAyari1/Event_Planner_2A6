#ifndef PLACE_H
#define PLACE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class place{
    public:
        place();
        place(int, int);
        int getId();
        int getEtat();
        bool ajouter();
        bool supprimer(int);
        bool modifier(place);
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficherTriId();
        QSqlQueryModel * afficherTriEt();
        QSqlQueryModel * afficherRechId(int);
        QSqlQueryModel * afficherRechEt(int);
    private:
        int idPlace, etatPlace, idParking;
};

#endif // PLACE_HZ
