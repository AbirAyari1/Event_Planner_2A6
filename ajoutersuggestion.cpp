#include "ajoutersuggestion.h"
#include "ui_ajoutersuggestion.h"
#include "suggestion.h"
#include "mainwindow.h"
#include "QMessageBox"
#include <QTime>
ajoutersuggestion::ajoutersuggestion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajoutersuggestion)
{
    ui->setupUi(this);
}

ajoutersuggestion::~ajoutersuggestion()
{
    delete ui;
}

void ajoutersuggestion::on_retour_clicked()
{
    MainWindow *m=new MainWindow();
    this->hide();
    m->show();

}

void ajoutersuggestion::on_pushButton_clicked()
{
    suggestion *a =new suggestion(ui->id_place->text(),ui->id_voiture->text(),ui->comboBox2->currentText(),ui->nomprop->text(),ui->time->text()) ;
   qDebug("Bouton ajouter client appuyee");
   if ( a->ajouter())
  QMessageBox::information(this,"confirmation","Ajout avec Succée.");
     else                 { QMessageBox::critical(this,"nope","Echec de l'ajout.");}
   MainWindow *f=new MainWindow();
   this->hide();
   f->show();

}

