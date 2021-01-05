#ifndef INVITATION_H
#define INVITATION_H
#include <QSqlQueryModel>
#include <QString>


class Invitation
{
private:
    int  idTable, positionInviteTable;
    QString nomInv;

public:
    Invitation();
    Invitation(QString, int, int);
    QString getNomInvite();
    int getIdITable();
    int getPositionInviteTable();
    bool ajouterInvitation();
    QSqlQueryModel * afficherInvitation();
    QSqlQueryModel * afficherNomInvite();
     QSqlQueryModel * afficherNomInvite1(QString nomInvite);
    QSqlQueryModel * afficherNomTable();
    QString nomInvite();
    QString numTable();
    bool supprimerInvitation(QString );
    bool modifierInvitation(QString );

};

#endif // INVITATION_H
