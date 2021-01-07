#include "modifiersuggestion.h"
#include "ui_modifiersuggestion.h"
#include "suggestion.h"
#include "mainwindow.h"
#include "QMessageBox"

modifiersuggestion::modifiersuggestion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifiersuggestion)
{
    ui->setupUi(this);
}
modifiersuggestion::~modifiersuggestion()
{
    delete ui;
}

void modifiersuggestion::on_pushButton_clicked()
{      suggestion *s=new suggestion();
    if(s->modifier(ui->id_place->text(),ui->id_voiture->text(),ui->comboBox2->currentText(),ui->nomprop->text(),ui->time->text()))
        QMessageBox::information(this,"confirmation","Modifié avec Succée.");
    else              QMessageBox::critical(this,"nope","Echec de l'Update.");
       MainWindow *m=new MainWindow;
       this->hide();
       m->show();
}

void modifiersuggestion::on_retour_clicked()
{
    MainWindow *m=new MainWindow;
    this->hide();
    m->show();
}
