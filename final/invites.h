#ifndef INVITES_H
#define INVITES_H
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QValidator>
#include <QRegExpValidator>

class Invites
{
private:
    QString nomInvite, prenomInvite, telInvite, emailInvite;

public:
    Invites(QString , QString, QString, QString);
    QString getTelInvite();
    QString getNomInvite();
    QString getPrenomInvite();
    QString getEmailInvite();
    bool ajouterInvite();
    QSqlQueryModel * afficherInvite();
    QSqlQueryModel * isUnique( QString tel);
    bool supprimerInvite(QString);
    bool modifierInvite(QString);
    Invites rechercherInvite(QString);
    Invites();

};

#endif // INVITES_H
