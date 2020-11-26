#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parking.h"
#include "place.h"
#include "QMessageBox"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabParking->setModel(tmpParking.afficher());
    ui->tabPlace->setModel(tmpPlace.afficher());
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ajouterParking_clicked(){
    int idParking = ui->idParking->text().toInt();
    int capaciteParking = ui->capaciteParking->text().toInt();
    int etatParking = ui->etatParking->text().toInt();
    parking pa(idParking, capaciteParking, etatParking);
    bool test = pa.ajouter();
    if(test){
        ui->tabParking->setModel(tmpParking.afficher());
        qDebug() <<"Parking ajoute";
    }else{
       qDebug() <<"Erreur d'ajout de parking";
    }
}

void MainWindow::on_ajouterPlace_clicked(){
    int idPlace = ui->idPlace->text().toInt();
    int etatPlace = ui->etatPlace->text().toInt();
    place pl(idPlace, etatPlace);
    bool test = pl.ajouter();
    if(test){
        ui->tabPlace->setModel(tmpPlace.afficher());
        qDebug() <<"Place ajoute";
    }else{
       qDebug() <<"Erreur d'ajout de place";
    }
}

void MainWindow::on_supprimerParking_clicked(){
    int idParkingSuppr = ui->idParkingSuppr->text().toInt();
    bool test = tmpParking.supprimer(idParkingSuppr);
    if(test){
        ui->tabParking->setModel(tmpParking.afficher());
    }
}

void MainWindow::on_supprimerPlace_clicked(){
    int idPlaceSuppr = ui->idPlaceSuppr->text().toInt();
    bool test = tmpPlace.supprimer(idPlaceSuppr);
    if(test){
        ui->tabPlace->setModel(tmpPlace.afficher());
    }
}

void MainWindow::on_modifierParking_clicked(){
    int idParking = ui->idParkingModif->text().toInt();
    int capaciteParking = ui->capaciteParkingModif->text().toInt();
    int etatParking = ui->etatParkingModif->text().toInt();
    parking pa(idParking, capaciteParking, etatParking);
    bool test = tmpParking.modifier(pa);
    if(test){
        ui->tabParking->setModel(tmpParking.afficher());
    }
}

void MainWindow::on_modifierPlace_clicked(){
    int idPlace = ui->idPlaceModif->text().toInt();
    int etatPlace = ui->etatPlaceModif->text().toInt();
    place pl(idPlace, etatPlace);
    bool test = tmpPlace.modifier(pl);
    if(test){
        ui->tabPlace->setModel(tmpPlace.afficher());
    }
}

void MainWindow::on_identifianttri_clicked(){
    ui->tabParking->setModel(tmpParking.afficherTriId());
}

void MainWindow::on_capacitetri_clicked(){
    ui->tabParking->setModel(tmpParking.afficherTriCap());
}

void MainWindow::on_etattri_clicked(){
    ui->tabParking->setModel(tmpParking.afficherTriEt());
}


void MainWindow::on_rechId_clicked(){
    int id = ui->idr->text().toInt();
    ui->tabParking->setModel(tmpParking.afficherRechId(id));
}

void MainWindow::on_rechCap_clicked(){
    int cap = ui->capr->text().toInt();
    ui->tabParking->setModel(tmpParking.afficherRechCap(cap));
}

void MainWindow::on_rechEt_clicked(){
    int rech = ui->etatr->text().toInt();
    ui->tabParking->setModel(tmpParking.afficherRechEt(rech));
}

void MainWindow::on_identifianttripl_clicked(){
    ui->tabPlace->setModel(tmpPlace.afficherTriId());
}

void MainWindow::on_etattripl_clicked(){
    ui->tabPlace->setModel(tmpPlace.afficherTriEt());
}

void MainWindow::on_rechIdpl_clicked(){
    int id = ui->idr->text().toInt();
    ui->tabPlace->setModel(tmpPlace.afficherRechId(id));
}

void MainWindow::on_rechEtpl_clicked(){
    int rech = ui->etatr->text().toInt();
    ui->tabPlace->setModel(tmpPlace.afficherRechEt(rech));
}

void MainWindow::on_envoyerMail_clicked(){
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("mariem.ayadi@esprit.tn");
    smtp.setPassword("marioumaayadi27..");
    MimeMessage message;
    message.setSender(new EmailAddress("mariem.ayadi@esprit.tn", "Agent"));
    message.addRecipient(new EmailAddress("habib.majoul@esprit.tn", "Administrateur"));
    message.setSubject("Alerte: Bus en panne");
    MimeText text;
    text.setText("Bus en panne, envoyer de l'aide\n");
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    if(smtp.sendMail(message)){
        QMessageBox::information(this, "OK", "Mail envoye correctement");
    }else{
        QMessageBox::critical(this, "Erreur", "Mail non envoye");
    }
    smtp.quit();
}
