#include "supprimer_eve.h"
#include "ui_supprimer_eve.h"

Supprimer_eve::Supprimer_eve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimer_eve)
{
    ui->setupUi(this);
}

Supprimer_eve::~Supprimer_eve()
{
    delete ui;
}
