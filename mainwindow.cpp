#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>
#include <iostream>
#include "QPrinter"
#include "QPrintDialog"
#include"connection.h"
#include<QMessageBox>
#include"avis.h"
#include "reclamation.h"
#include "suggestion.h"
#include"ajouteravis.h"
#include "midifieravis.h"
#include "ajouterreclamation.h"
#include "ajoutersuggestion.h"
#include "modifiersuggestion.h"
#include "modifierreclamation.h"
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QItemSelectionModel>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <qtextbrowser.h>

#include <QPropertyAnimation>
#include <QSound>
#include <QInputDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QTranslator>
#include <QPropertyAnimation>
#include <QSound>
#include <QTranslator>
#include "login.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino_is_available = false;
    arduino_port_name = "COM4";
    arduino = new QSerialPort;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
           if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
               if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                   if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                       arduino_port_name = serialPortInfo.portName();
                       arduino_is_available = true;
                   }
               }
           }
       }

       if(arduino_is_available){
           // open and configure the serialport
           arduino->setPortName(arduino_port_name);

           arduino->setBaudRate(QSerialPort::Baud9600);
           arduino->setDataBits(QSerialPort::Data8);

           arduino->setParity(QSerialPort::NoParity);
           arduino->setStopBits(QSerialPort::OneStop);
           arduino->setFlowControl(QSerialPort::NoFlowControl);
           arduino->open(QSerialPort::ReadWrite);

             QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
       }else{
           // give error message if not available
           QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
       }



    avis *e=new avis();
    suggestion *s=new suggestion();
    reclamation *r=new reclamation();
    ui->table_avis->setModel(e->affichage(ui->comboBox->currentText()));
    ui->table_view_7->setModel(s->affichage(ui->comboBox_5->currentText()));
    ui->table_view_8->setModel(r->affichage(ui->comboBox_7->currentText()));
}

MainWindow::~MainWindow()
{
    {
       // if(arduino->isOpen()){
              //  arduino->close();
            }
    delete ui;
}


void MainWindow::on_pushButton_39_clicked()
{
    QSound::play("C:/Users/ahmed/click.wav");

    ajouteravis *f=new ajouteravis();
             f->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
          this->hide();
          f->show();
}

void MainWindow::on_pushButton_37_clicked()
{    QSound::play("C:/Users/ahmed/click.wav");
    avis *a=new avis();
    QString j=ui->table_avis->selectionModel()->selectedIndexes().at(0).data().toString();
    if(a->supprimer(j))
    {
        QMessageBox::information(this,"confirmation","Suppression avec Succée.");
    }
    else                {  QMessageBox::critical(this,"nope","Echec de Suppression.");}

}

void MainWindow::on_pushButton_29_clicked()
{
     QSound::play("C:/Users/ahmed/click.wav");
    midifieravis *m=new midifieravis();
    m->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    this->hide();
    m->show();
}

void MainWindow::on_pushButton_46_clicked()
{   QSound::play("C:/Users/ahmed/click.wav");
    ajoutersuggestion *f=new ajoutersuggestion();
    this->hide();
    f->show();

}

void MainWindow::on_pushButton_clicked()
{
   QSound::play("C:/Users/ahmed/click.wav");
    avis *e=new avis();
     ui->table_avis->setModel(e->affichage(ui->comboBox->currentText()));
}

void MainWindow::on_pushButton_2_clicked()
{

     QSound::play("C:/Users/ahmed/click.wav");
     avis *e=new avis();
    ui->table_avis->setModel(e->recherche(ui->recherche_avis->text()));
}

void MainWindow::on_pushButton_3_clicked()
{
     QSound::play("C:/Users/ahmed/click.wav");
     suggestion *s=new suggestion();
    ui->table_view_7->setModel(s->affichage(ui->comboBox_5->currentText()));

}

void MainWindow::on_pushButton_36_clicked()
{
     QSound::play("C:/Users/ahmed/click.wav");
    modifiersuggestion *ms=new modifiersuggestion();
    this->hide();
    ms->show();
}

void MainWindow::on_pushButton_47_clicked()
{
     QSound::play("C:/Users/ahmed/click.wav");
    suggestion *a=new suggestion();
        QString j=ui->table_view_7->selectionModel()->selectedIndexes().at(0).data().toString();
        if(a->supprimer(j))
        {
            QMessageBox::information(this, "confirmation","Suppression avec Succée.");
        }
        else                {  QMessageBox::critical(this,"nope","Echec de Suppression.");}

}

void MainWindow::on_pushButton_4_clicked()
{
     QSound::play("C:/Users/ahmed/click.wav");
    suggestion *e=new suggestion();
    ui->table_view_7->setModel(e->recherche(ui->lineEdit_41->text()));
}

void MainWindow::on_pushButton_48_clicked()
{
     QSound::play("C:/Users/ahmed/click.wav");
    ajouterreclamation *r=new ajouterreclamation();
            this->hide();
            r->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
            r->show();
}



void MainWindow::on_pushButton_49_clicked()
{
     QSound::play("C:/Users/ahmed/click.wav");
    reclamation *a=new reclamation();
        QString j=ui->table_view_8->selectionModel()->selectedIndexes().at(0).data().toString();
        if(a->supprimer(j))
        {
            QMessageBox::information(this, "confirmation","Suppression avec Succée.");
        }
        else                {  QMessageBox::critical(this,"nope","Echec de Suppression.");}


}

 void MainWindow::on_pushButton_6_clicked()
{
    reclamation *a=new reclamation();
  ui->table_view_8->setModel(a->recherchereclamation(ui->lineEdit_42->text()));

}

void MainWindow::on_pushButton_38_clicked()
{
    modifierreclamation *m=new modifierreclamation();
    this->hide();
    m->show();
}

void MainWindow::on_pushButton_7_clicked()
{

    QSound::play("C:/Users/ahmed/click.wav");

    QPrinter printer;
         printer.setPrinterName("printer name");
         QPrintDialog dialog(&printer,this);

         if(QDialog::Accepted == dialog.exec())
         {
             if(QPrinter::Landscape != printer.orientation())
             {
                 printer.setOrientation(QPrinter::Landscape);
             }
             QPoint startPoint = QPoint(1,1);
             QRegion printRegion = QRegion( 1, 1, printer.paperRect().width(),printer.paperRect().height() );
                 for( int i = 0; i < 1; ++i )
                 {
                     ui->table_view_8->render( &printer, startPoint, printRegion, QWidget::DrawChildren );
                 }
         }


     QMessageBox::information(this,"IMPRESSION ","PROCEDURE IMPRESSION TERMINEE AVEC SUCCES");
     qDebug()<<"IMPRESSION PRETE"<<endl;

    }


void MainWindow::on_pushButton_8_clicked()

{
suggestion a;
a.creerpdf();

}



 /*   void MainWindow::on_confirmer_langue_clicked()
    {
        if (ui->comboBox_langue->currentText()=="Français")
        {
            translator->load("C:/Users/ahmed/Documents/try1/esprit2021/wedding_planner_fr");
            qApp->installTranslator(translator);
            ui->retranslateUi(this);
            ui->comboBox_langue->setCurrentText("Français");
        }
        else if (ui->comboBox_langue->currentText()=="English")
        {
            translator->load("C:/Users/ahmed/Documents/try1/esprit2021/wedding_planner_en");
            qApp->installTranslator(translator);
            ui->retranslateUi(this);
            ui->comboBox_langue->setCurrentText("English");
        }
    }


*/



void MainWindow::on_pushButton_9_clicked()
{
    reclamation a;
    a.creerpdf();
}
