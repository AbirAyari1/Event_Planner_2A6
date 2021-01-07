#include "modifierreclamation.h"
#include "ui_modifierreclamation.h"
#include "reclamation.h"
#include "QMessageBox"

modifierreclamation::modifierreclamation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifierreclamation)
{
    ui->setupUi(this);
}

modifierreclamation::~modifierreclamation()
{
    delete ui;
}

void modifierreclamation::on_pushButton_clicked()
{
    reclamation *m=new reclamation();
    if(m->modifier(ui->id_client->text(),ui->id_edit_reclam->text(),ui->dateTimeEdit->text(),ui->comboBox->currentText()))
    QMessageBox::information(this,"Reservation","modifier avec succes");
    else  QMessageBox::critical(this,"Reservation","modification non reussite");
    MainWindow *n=new MainWindow();
    this->hide();
    n->show();
}

void modifierreclamation::on_retour_clicked()
{
    MainWindow *n=new MainWindow();
    this->hide();
    n->show();
}
