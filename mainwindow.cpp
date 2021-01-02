#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rh.h"
#include <QMessageBox>


// include the header of your workspace here

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id="";
    e =3;
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

          data=A.read_from_arduino();

          qDebug() <<data ;
       A.write_to_arduino("3");

}
void MainWindow::update_label(){
    data=A.read_from_arduino();
    id = id + QString::fromStdString(data.toStdString());
    qDebug() <<id ;
        if (id=="67A1653C"){
            A.write_to_arduino("1");
           close();
            rh *ws;
            ws = new rh();
            ws->setWindowTitle("gestion emp");
            ws->show();


        }
     else if (id.length()==8){
            e--;
           A.write_to_arduino("0");
        if (e<=0){
            ui->lineEdit_userID->setEnabled(0);
            ui->lineEdit_password->setEnabled(0);
            ui->pushButton_submit_2->setEnabled(0);
            ui->pushButton_submit->setEnabled(0);

            QMessageBox::critical(nullptr,QObject::tr("Alerte"),
                                     QObject::tr("%n tentative(s) restantes", "", e), QMessageBox::Cancel);
        }else {
            QMessageBox::information(nullptr,QObject::tr("Oups"),
                                     QObject::tr("%n message(s) saved", "", e), QMessageBox::Cancel);
        }
    }
        if (e<=0){
             A.write_to_arduino("2");

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
    QString users="adminRH adminCL"; // you add your ID in format admin(first 2 letters of your departement name)
    bool user_ex = users.contains(userID);


    //check if password is in default list
    QString password ="ADM-RH ADM-CL"; // you add your password in format ADM-(first 2 letters of your departement name)
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
ws->show();
}

//open Coli lettre Space
/*
 ---------------pour tester------------
 username : 12345678
 mdp : EMP-CL-12345678

 ou bien

 username : adminCL
 mdp : ADM-CL
 --------------------------------------
*/


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
