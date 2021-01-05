#ifndef DIALOGEEMMANUEL_H
#define DIALOGEEMMANUEL_H

#include "invites.h"
#include "table.h"
#include "invitation.h"


#include <QDialog>

namespace Ui {
class DialogeEmmanuel;
}

class DialogeEmmanuel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogeEmmanuel(QWidget *parent = nullptr);
    ~DialogeEmmanuel();

private slots:
    void on_pushButton_ajoute_invite_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void on_tableInvite_activated(const QModelIndex &index);

    void on_on_pushButton_ModInv_clicked_clicked();

    void on_on_pushButton_SupprInv_clicked_clicked();

    void on_pushButton_filter_invite_clicked();

    void on_pushButton_print_invite_clicked();

    void on_lineEdit_recherche_inv_textChanged(const QString &arg1);



    void on_pushButton_ajouter_table_clicked();

    void on_tabWidget_3_tabBarClicked(int index);

    void on_tableEvent_activated(const QModelIndex &index);



    void on_pushButton_ModTab_enregrs_clicked();

    void on_pushButton_suppr_table_clicked();

    void browse();

    void sendMail();

private:
    Ui::DialogeEmmanuel *ui;
    Invites tempInv;
    Table tempTable;
    Invitation tempInvitation;
    QStringList files;

};

#endif // DIALOGEEMMANUEL_H
