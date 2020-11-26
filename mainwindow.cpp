#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QLineEdit>
#include "evenement.h"
#include <QDebug>
#include<QSystemTrayIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
  ui->setupUi(this);
   ui->comboBox->addItem(QIcon(":/rec/rec/Argent icon.png"),"Prix");
   ui->comboBox->addItem(QIcon(":/rec/rec/choix icone.jpg"),"Choix");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_Statistique_eve_clicked()
{
    QMessageBox::information(this,"title",ui->comboBox_2->currentText());
}


void MainWindow::on_pb_valider_ajout_evenement_clicked()
{
    int id_eve= ui->Id_eve_2->text().toInt();
    QString nom_eve= ui->Nom_eve_2->text();
    QString type_eve= ui->Type_eve_2->text();
    int prix= ui->Prix_2->text().toInt();
    int temps= ui->Temps_2->text().toInt();

    Evenement ev;

    bool test=ev.ajouter();
    if(test)
    {
       mysystem->showMessage(tr("Notification"),tr("ajout avec succes"));
        ui->tab->setModel(tmpeve.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un vol"),
                      QObject::tr("vol ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else if(!test)
    {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un vol"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
}



void MainWindow::on_pb_valider_supp_eve_clicked()
{
    int id_eve = ui->id_eve_2->text().toInt();
        bool test=tmpeve.supprimer(id_eve);
        if(test)
        {mysystem->showMessage(tr("Notification"),tr("supprimer avec succes"));
            ui->tab_liste_aff->setModel(tmpeve.afficher());
}



void MainWindow::on_pb_valider_modif_eve_clicked()
{
    int id_eve= ui->id_eve_3->text().toInt();
    QString nom_eve= ui->Nom_eve_6->text();
    QString type_eve= ui->type_eve_mod->text();
    int prix= ui->Prix_5->text().toInt();
    int temps= ui->Temps_3->text().toInt();

    bool test=tmpeve.modifier( Id_eve, nom_eve,type_eve,prix,temps);
       if (test)
       {
       mysystem->showMessage(tr("Notification"),tr("modifier avec succes"));
            ui->tab_liste_aff->setModel( tmpeve.afficher());

            // QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                  //       QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
         }
         /*else
             QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}*/
}




void MainWindow::on_Rechercher_eve_clicked()
{
    {int id_eve;

        id_eve=ui->Rech_eve_liste->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabrech->setModel(tmpeve.Rechercher(id_eve));
    //QMessageBox::information(nullptr, QObject::tr("vol existe  !"),
            //    QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
    }


    /*(test==(false))
    {
         ui->tabrech->setModel(tmpeve.Rechercher(id_eve));

        QMessageBox::information(nullptr, QObject::tr("vol n'existe pas"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }*/

    }
}

void MainWindow::on_pb_valider_ajout_pack_clicked()
{
    int id_pack= ui->Id_pack->text().toInt();
    QString nom_eve= ui->Nom_eve_2->text();
    QString type_eve= ui->Type_eve_2->text();
    int prix= ui->Prix_2->text().toInt();
    int temps= ui->Temps_2->text().toInt();

    Evenement ev;

    bool test=ev.ajouter();
    if(test)
    {
       mysystem->showMessage(tr("Notification"),tr("ajout avec succes"));
        ui->tab->setModel(tmpeve.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un vol"),
                      QObject::tr("vol ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
