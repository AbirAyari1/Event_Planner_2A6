#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "employe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpemploye.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // ajouter employe
{
 int id =ui->lineEdit_7->text().toInt();
 QString nom=ui->lineEdit_8->text();
 QString prenom=ui->lineEdit_9->text();
 QString email=ui->lineEdit_10->text();
 QString fonction=ui->comboBox->currentText();
 int score=ui->lineEdit_11->text().toInt();

Employe e(id,nom,prenom,email,fonction,score);
bool test=e.ajouter();
if (test)
{ui->tableView->setModel(tmpemploye.afficher()); // to refresh
QMessageBox::information(nullptr,QObject::tr("Ajouer Employé"),
                         QObject::tr("Employé ajouté.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}}



void MainWindow::on_pushButton_40_clicked() // supprimer employe
{ int id=ui->lineEdit_23->text().toInt();
  bool test=tmpemploye.supprimer(id);
 if (test)
 { ui->tableView->setModel(tmpemploye.afficher());
  QMessageBox::information(nullptr,QObject::tr("Supprimer employé"),
                           QObject::tr("Employé supprimé.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
 }}
