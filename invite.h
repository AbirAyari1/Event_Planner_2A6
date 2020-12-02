#ifndef INVITE_H
#define INVITE_H

#include <QWidget>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class Invite;
}

class Invite : public QWidget
{
    Q_OBJECT

public:
    explicit Invite(QWidget *parent = nullptr);
    Invite(QString , QString, QString, QString);
    QString getTelInvite();
    QString getNomInvite();
    QString getPrenomInvite();
    QString getEmailInvite();
    bool ajouterInvite();
    QSqlQueryModel * afficherInvite();
    bool supprimerInvite(QString);
    bool modifierInvite(QString);
    Invite rechercherInvite(QString);
    ~Invite();

private:
    QString nomInvite, prenomInvite, telInvite, emailInvite;  

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Afficher_clicked();

    void on_pushButton_Modifier_clicked();

    void on_pushButton_Suppr_clicked();

    void on_pushButton_Home_clicked();

    void on_pushButton_ajoute_invite_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_ModInv_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_filter_invite_clicked();

    void on_pushButton_print_invite_clicked();

private:
    Ui::Invite *ui;

signals :
    void homeCliked();
};

#endif // INVITE_H
