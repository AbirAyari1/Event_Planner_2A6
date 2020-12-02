#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include "invitation.h"

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    Table(QString,QString,int);
    QString getNomTable();
    QString getTypeTable();
    bool ajouterTable();
    QSqlQueryModel * afficherTable();
    bool supprimerTable(QString);
    bool modifierTable(QString);

    ~Table();

private slots:
    void on_pushButton_Home3_clicked();

    void on_pushButton_Ajouter_Table_clicked();

    void on_pushButton_Afficher_Table_clicked();

    void on_pushButton_Modifier_Table_clicked();

    void on_pushButton_Supprimer_Table_clicked();

    void on_pushButton_ajouter_table_clicked();

    void on_pushButton_suppr_table_clicked();

    void on_pushButton_3_clicked();

signals :
    void homeCliked();

private:
    Ui::Table *ui;
    QString nomTable, typeTable;
    int nbPlace;
    Invitation tmp_inv;
};

#endif // TABLE_H
