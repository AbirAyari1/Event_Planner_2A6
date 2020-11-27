#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "fournisseur.h"
#include "marchandise.h"
#include "commande.h"
#include "notification.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_ajouter_fournisseur_clicked();

    void on_pushButton_supprimer_fournisseur_clicked();

    void on_pushButton_modifier_fournisseur_clicked();

    void on_pushButton_ajouter_marchandise_clicked();

    void on_pushButton_modifier_marchandise_clicked();

    void on_pushButton_supprimer_marchandise_clicked();

    void on_pushButton_ajouter_commande_clicked();

    void on_pushButton_supprimer_commande_clicked();

    void on_pushButton_modifier_commande_clicked();

    void on_pushButton_rechercher_fournisseur_clicked();

    void on_pushButton_rechercher_marchandise_clicked();

    void on_pushButton_rechercher_commande_clicked();


    void on_radioButton_tri_fournisseur_clicked();



    void on_radioButton_type_marchandise_clicked();

    void on_radioButton_quantite_marchandise_clicked();

    void on_radioButton_prix_marchandise_clicked();


    void on_radioButton_numero_commande_clicked();

    void on_radioButton_produit_commande_clicked();

    void on_radioButton_quantite_commande_clicked();

    void on_radioButton_prix_total_commande_clicked();



    void on_pushButton_imprimer_commande_clicked();


    void on_radioButton_id_commande_clicked();

    void on_radioButton_numero_marchandise_clicked();

    void on_radioButton_produit_marchandise_clicked();

    void mailSent(QString );

    void on_pushButton_Mail_clicked();

    void on_pushButton_Statistique_clicked();


private:
    Ui::MainWindow *ui;
    fournisseur tmpfournisseur;
    marchandise tmpmarchandise;
    commande tmpcommande;
    Notification N;


};
#endif // MAINWINDOW_H
