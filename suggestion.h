#ifndef SUGGESTION_H
#define SUGGESTION_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QAbstractItemModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
#include <QTime>
class suggestion
{
public:
    suggestion(){};
    suggestion( QString id_place, QString id_voiture,QString type_voit,QString nomprop,QString time);
    bool ajouter();
    bool supprimer(QString id_voiture);
    QSqlQueryModel* affichage(QString);
    bool modifier(QString,QString,QString,QString,QString);
    QSqlQueryModel* recherche(QString);
    void creerpdf();
private:
    QString id_voiture,id_place;

    QString type_voit;
QString nomprop;
QString time;
};

#endif // SUGGESTION_H
