#include "midifieravis.h"
#include "ui_midifieravis.h"
#include "avis.h"
#include "QMessagebox.h"
#include "connection.h"
#include "mainwindow.h"
midifieravis::midifieravis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::midifieravis)
{
    ui->setupUi(this);
}

midifieravis::~midifieravis()
{
    delete ui;
}

void midifieravis::on_pushButton_clicked()
{       avis *av=new avis();

    if(av->modifier(ui->id_client_avis->text(),ui->id_edit_avis->text(),ui->avis_edit->text(),ui->film_edit->text()))

        QMessageBox::information(this,"confirmation","Modifié avec Succée.");
    else              QMessageBox::critical(this,"nope","Echec de l'Update.");

        MainWindow *f=new MainWindow();

              this->hide();
              f->show();
}

void midifieravis::on_retour_clicked()
{
    MainWindow *f=new MainWindow();

          this->hide();
          f->show();
}
