#include "dialogasma.h"
#include "ui_dialogasma.h"
#include "salle.h"
#include <QMessageBox>
#include"reservation.h"
#include "smtp.h"

DialogAsma::DialogAsma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAsma)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(stmp.afficher());
    ui->tableView_3->setModel(stmp.afficher());
    ui->tableView->setModel(stmp.afficher());
    ui->tableView_6->setModel(rtmp.afficher());
    ui->tableView_4->setModel(rtmp.afficher());
    ui->tableView_5->setModel(rtmp.afficher());

    //E-mailing
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    //music
    player= new QMediaPlayer(this) ;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Asma Srairi/Downloads/Relax - Smooth Trap Soul Hip Hop Beat Chill Instrumental (Prod. Tower B. x L.E.M.).mp3")) ;
    player->setVolume(20);
    player->play();

    //control de saisie
    ui->lineEdit_2->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_3->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_10->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_9->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_18->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_25->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_11->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_24->setValidator(new QIntValidator(0,999999999));


    ui->lineEdit_7->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_22->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_23->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_12->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_17->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_13->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_14->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_15->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));
    ui->lineEdit_16->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{0,20}"),this));


}




DialogAsma::~DialogAsma()
{
    delete ui;
}


// ajouter salle
void DialogAsma::on_pb_ajouter_clicked()
{
    //récuperer les infos saisies dans l'interface
    int ID = ui->lineEdit_2->text().toInt();
    QString nom=ui->lineEdit_7->text();
    QString type=ui->lineEdit_22->text();
    QString lieu=ui->lineEdit_23->text();


   salle e(ID,nom,type,lieu);
   bool test=e.ajouter();


   if(test)
   {
       ui->tableView_2->setModel(stmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                   QObject::tr("OK.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else
       QMessageBox::critical(nullptr, QObject::tr("Ajout non effectué"),
                   QObject::tr("KO.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }

//void MainWindow::on_pb_ajouter_clicked()



// supprimer salle
void DialogAsma::on_pushButton_7_clicked()
{
    int id =ui->lineEdit_3->text().toInt();
    bool test=stmp.supprimer(id);
    if (test)
{
     ui->tableView_2-> setModel(stmp.afficher());//refresh*
        QMessageBox::information(nullptr, QObject::tr("Suppression effectué"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox::critical(nullptr, QObject::tr("Suppression non effectué"),
                    QObject::tr("KO.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}



//modifier salle
void DialogAsma::on_pushButton_9_clicked()
{
    QString nom=ui->lineEdit_12->text();
        QString type=ui->lineEdit_13->text();
        QString lieu=ui->lineEdit_17->text();
        int id=ui->lineEdit_11->text().toInt() ;

        salle sa ;
        bool test=sa.modifier(id,nom,type,lieu) ;
        QMessageBox msBox;
        if(test)
        {
            ui->tableView_3->setModel(sa.afficher());
            ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            msBox.setText("modification reussite");
            msBox.exec();
        }
        else
        {
            msBox.setText("ERREUR");
            msBox.exec();}
        ui->lineEdit_13->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_12->clear();

}


//tri salle par nom
void DialogAsma::on_pushButton_clicked()
{
    QMessageBox msgBox ;

             QSqlQueryModel *model = new QSqlQueryModel();
                   model->setQuery("select * from salle order by id ASC,nom");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
                   ui->tableView->setModel(model);
                   ui->tableView->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();
}


//tri salle par type
void DialogAsma::on_pushButton_2_clicked()
{
    QMessageBox msgBox ;

             QSqlQueryModel *model = new QSqlQueryModel();
                   model->setQuery("select * from salle order by id ASC,type");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
                   ui->tableView->setModel(model);
                   ui->tableView->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();
}


//tri salle par lieu
void DialogAsma::on_pushButton_3_clicked()
{
    QMessageBox msgBox ;

             QSqlQueryModel *model = new QSqlQueryModel();
                   model->setQuery("select * from salle order by id ASC,lieu");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
                   ui->tableView->setModel(model);
                   ui->tableView->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();
}



//ajout reservation
void DialogAsma::on_pushButton_5_clicked()
{


    QString nom_client=ui->lineEdit_4->text();
    QString prenom_client=ui->lineEdit_5->text();
    QString nom_salle=ui->lineEdit_6->text();
    QString date_reservation=ui->lineEdit_19->text();
    int nb_heure=ui->lineEdit_20->text().toInt();
    int ID = ui->lineEdit_10->text().toInt();


   reservation m(nom_client,prenom_client,nom_salle,date_reservation,nb_heure,ID);
   bool test=m.ajouter();


   if(test)
   {
       ui->tableView_6->setModel(rtmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                   QObject::tr("OK.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else
       QMessageBox::critical(nullptr, QObject::tr("Ajout non effectué"),
                   QObject::tr("KO.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }


//supprimer reservation
void DialogAsma::on_pushButton_17_clicked()
{
    int id =ui->lineEdit_18->text().toInt();
    bool test=rtmp.supprimer(id);
    if (test)
{
     ui->tableView_6-> setModel(rtmp.afficher());//refresh*
        QMessageBox::information(nullptr, QObject::tr("Suppression effectué"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox::critical(nullptr, QObject::tr("Suppression non effectué"),
                    QObject::tr("KO.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



//modifier réservation
void DialogAsma::on_pushButton_10_clicked()
{
    QString nom_client=ui->lineEdit_14->text();
            QString prenom_client=ui->lineEdit_15->text();
            QString date_reservation=ui->lineEdit_16->text();
            QString nom_salle=ui->lineEdit_21->text();
            int nb_heure=ui->lineEdit_24->text().toInt() ;
            int id=ui->lineEdit_25->text().toInt() ;

           reservation sa ;
            bool test=sa.modifier(nom_client,prenom_client,date_reservation,nom_salle,nb_heure,id) ;
            QMessageBox msBox;
            if(test)
            {
                ui->tableView_4->setModel(rtmp.afficher());
                ui->tableView_6->setModel(rtmp.afficher());
                ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                msBox.setText("modification reussite");
                msBox.exec();
            }
            else
            {
                msBox.setText("ERREUR");
                msBox.exec();}
            ui->lineEdit_14->clear();
            ui->lineEdit_15->clear();
            ui->lineEdit_16->clear();
            ui->lineEdit_21->clear();
            ui->lineEdit_24->clear();
            ui->lineEdit_25->clear();
}





//recherche reservation
void DialogAsma::on_pushButton_15_clicked()
{
    QMessageBox msgBox ;

            QSqlQueryModel *model = new QSqlQueryModel();
            QString cod;
            cod = ui->lineEdit_9->text();
            model->setQuery("Select * from reservation where id = '"+cod+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_client"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom_client"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_reservation"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_salle"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nb_heure"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("id"));
            ui->tableView_5->setModel(model);
            ui->tableView_5->show();
            msgBox.setText("reservation trouvée");
            msgBox.exec();
            ui->lineEdit_9->clear();



}



//E-mailing
void  DialogAsma::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}


void   DialogAsma::sendMail()
{
    Smtp* smtp = new Smtp("asma.srairi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("asma.srairi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("asma.srairi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   DialogAsma::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

