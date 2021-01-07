#include "ajouteravis.h"
#include "ui_ajouteravis.h"
#include "mainwindow.h"
#include "avis.h"
#include <QMessageBox>
#include"connection.h"
#include "QWidget"

ajouteravis::ajouteravis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajouteravis)
{
    ui->setupUi(this);
}

ajouteravis::~ajouteravis()
{
    delete ui;
}

void ajouteravis::on_pushButton_clicked()
{
    avis *a =new avis(ui->id_client_avis->text(),ui->id_edit_avis->text(),ui->avis_edit->text(),ui->film_edit->text()) ;
   qDebug("Bouton ajouter avis appuyee");
   if ( a->ajouter())
  QMessageBox::information(this,"confirmation","Ajout avec Succée.");
     else                  QMessageBox::critical(this,"nope","Echec de l'ajout.");
   MainWindow *f=new MainWindow();

         this->hide();
         f->show();
}


void ajouteravis::on_retour_clicked()
{
    MainWindow *f=new MainWindow();

          this->hide();
          f->show();

}
