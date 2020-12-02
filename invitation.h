#ifndef INVITATION_H
#define INVITATION_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class Invitation;
}

class Invitation : public QWidget
{
    Q_OBJECT

public:
    explicit Invitation(QWidget *parent = nullptr);
    Invitation(int, int, int);
    int getIdInvitation();
    int getIdITable();
    int getPositionInviteTable();
    bool ajouterInvitation();
    QSqlQueryModel * afficherInvitation();
    QSqlQueryModel * afficherNomInvite();
    QSqlQueryModel * afficherNomTable();
    bool supprimerInvitation(int);
    bool modifierInvitation(int);
    ~Invitation();

private:
    Ui::Invitation *ui;
    int idInvite, idTable, positionInviteTable;

signals :
    void homeCliked();

private slots:
    void on_pushButton_Home2_clicked();
    void on_pushButton_Ajouter_Invitation_clicked();
    void on_pushButton_Afficher_Invitation_clicked();
    void on_pushButton_Modifier_Invitation_clicked();
    void on_pushButton_Supprimer_Invitation_clicked();

    void on_comboBox_personnes_ajouter_currentIndexChanged(const QString &arg1);
};

#endif // INVITATION_H
