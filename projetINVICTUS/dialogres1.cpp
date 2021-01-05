#include "dialogres1.h"
#include "ui_dialogres1.h"

Dialogres1::Dialogres1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogres1)
{
    ui->setupUi(this);
}

Dialogres1::~Dialogres1()
{
    delete ui;
}
