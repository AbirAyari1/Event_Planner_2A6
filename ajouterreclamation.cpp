#include "ajouterreclamation.h"
#include "ui_ajouterreclamation.h"
#include "mainwindow.h"
#include "reclamation.h"
#include "QMessageBox"

ajouterreclamation::ajouterreclamation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajouterreclamation)
{
    ui->setupUi(this);
}

ajouterreclamation::~ajouterreclamation()
{
    delete ui;
}

void ajouterreclamation::on_retour_clicked()
{
    MainWindow *m=new MainWindow();
    this->hide();
    m->show();

}
void ajouterreclamation::on_pushButton_clicked()
{ reclamation *r=new reclamation(ui->id_client->text(),ui->id_reclamation->text(),ui->dateTimeEdit->text(),ui->comboBox->currentText());
  if(r->ajouter())
  {QMessageBox::information(this,"Reservation","reclamation ajoutée");}
  else
      QMessageBox::critical(this,"Reservation","ajout non reussi");
  MainWindow *m=new MainWindow();
  this->hide();
  m->show();
}
