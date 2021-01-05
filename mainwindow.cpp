#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rh.h"
#include "dialogamen.h"
#include "C:\Users\Laptop\Downloads\final2\final\dialogeemmanuel.h"
#include <QMessageBox>
#include "C:\Users\Laptop\Documents\Project\AbirAyari\Event_Planner_2A6 - Copie\projetINVICTUS\dialogasma.h"
#include "dialogahmed.h"

// include the header of your workspace here

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id="";
     e =3; // nombre de tentatives
    Connection C;
    C.createConnection();
    ui->statusbar->addPermanentWidget(ui->label_3);

   int ret =A.connect_arduino(); // c pour lancer la cnx arduino
                switch (ret) {
                case(0): qDebug()<<" arduino is available and connected to " <<A.getarduino_port_name();
                break ;
                case(1): qDebug()<<" arduino is available but not connected to " <<A.getarduino_port_name();
                break ;
                case(-1): qDebug()<<" arduino is  not available   ";
                break ;
                               }
          QObject::connect(A.getserial(),SIGNAL(readyRead()) ,this,SLOT(update_label())) ;


              A.write_to_arduino("3");

}
void MainWindow::update_label(){
    data=A.read_from_arduino();
    id = id + QString::fromStdString(data.toStdString());
    qDebug() <<id ;
        if ((id=="67A1653C")&&(id.length()==8)){
            A.write_to_arduino("1");
           close();
            rh *ws;
            ws = new rh();
            ws->setWindowTitle("gestion emp");
            ws->show();


        }
     else if ((id.length()==8)&&(id!="67A1653C")){
            e--;
           A.write_to_arduino("0");
        if (e<=0){
             A.write_to_arduino("2");
            ui->lineEdit_userID->setEnabled(0);
            ui->lineEdit_password->setEnabled(0);
            ui->pushButton_submit_2->setEnabled(0);
            ui->pushButton_submit->setEnabled(0);

            QMessageBox::critical(nullptr,QObject::tr("Alerte"),
                                     QObject::tr("Application bloquée"), QMessageBox::Cancel);
        }else {
            QMessageBox::information(nullptr,QObject::tr("Erreur d'authentification "),
                                     QObject::tr("%n tentative(s) restantes(s)", "", e), QMessageBox::Cancel);
        }
    }

}
MainWindow::~MainWindow()
{

    delete ui;
}

/*QString MainWindow::user () const{

     return ui->lineEdit_userID->text();
 }
*/

void MainWindow::on_pushButton_submit_clicked()
{
   // QString userID;


    //extract userId and password
    //tmp=user();
    //userID=user();
    QString userID=ui->lineEdit_userID->text();
    QString given_password= ui->lineEdit_password->text();

    //check if userid is a number
    bool num ;
    int a=userID.toInt(&num,10);
    a++;

    //check if user is in default list
    QString users="adminRH adminFM adminIN adminRS adminEV"; // you add your ID in format admin(first 2 letters of your departement name)
    bool user_ex = users.contains(userID);


    //check if password is in default list
    QString password ="ADM-RH ADM-FM ADM-IN ADM-RS ADM-EV"; // you add your password in format ADM-(first 2 letters of your departement name)
    bool pass_ex = password.contains(given_password);


QSqlQuery qry;
 int count=0;
if(qry.exec( "select * from EMPLOYE where ID='"+userID+"'and MDP='"+given_password+"'" ))
{

    while(qry.next()) {

        count++;
    }

if (count<1)
    ui->statusbar->showMessage("UserID and Password don't match",3000);

}
if(count==1 || (user_ex && pass_ex)){
close();

//open RH Space
/*
 ---------------pour tester------------
 username : 09870668
 mdp : EMP-RH-09870668

 ou bien

 username : adminRH
 mdp : ADM-RH
 --------------------------------------
*/

if (given_password.mid(4,2)=="RH"){ //given_password.mid(4,2)=="XX" -> XX are the 1st 2 letters of your departement name uppercased
    rh *ws;
    ws = new rh();
    ws->setWindowTitle("gestion emp");
    ws->show();}

if (given_password.mid(4,2)=="FM"){ //given_password.mid(4,2)=="XX" -> XX are the 1st 2 letters of your departement name uppercased
        Dialogamen *fcm;
        fcm = new Dialogamen();
        fcm->setWindowTitle("gestion fournisseurs");
    fcm->show();
    }

if (given_password.mid(4,2)=="IN"){ //given_password.mid(4,2)=="XX" -> XX are the 1st 2 letters of your departement name uppercased
       DialogeEmmanuel *inv;
        inv = new DialogeEmmanuel();
        inv->setWindowTitle("gestion des invites");
    inv->show();
    }

if (given_password.mid(4,2)=="RS"){ //given_password.mid(4,2)=="XX" -> XX are the 1st 2 letters of your departement name uppercased
       DialogAsma *rs;
        rs = new DialogAsma();
        rs->setWindowTitle("gestion des invites");
    rs->show();
    }

if (given_password.mid(4,2)=="EV"){ //given_password.mid(4,2)=="XX" -> XX are the 1st 2 letters of your departement name uppercased
       DialogAhmed *ev;
        ev = new DialogAhmed();
        ev->setWindowTitle("gestion des evenement");
    ev->show();
    }




}//end test login
    else if( userID.length()!= 8 )
           ui->statusbar->showMessage("Check the userID input format",3000);
    else if( given_password.length()<4 )
           ui->statusbar->showMessage("Password too short",3000);


}

void MainWindow::on_pushButton_submit_2_clicked()
{
    id="";
     ui->lineEdit_userID->clear();
      ui->lineEdit_password->clear();
}
