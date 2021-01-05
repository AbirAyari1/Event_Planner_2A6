#include "dialogamen.h"
#include "ui_dialogamen.h"
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QPrinter>
#include <QPrintDialog>
#include "fournisseur.h"
#include "marchandise.h"
#include "commande.h"
#include "smtp.h"
#include <QDebug>
#include<QComboBox>
#include <QPieSlice>
#include <QPieSeries>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include"QSortFilterProxyModel"
#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>
QT_CHARTS_USE_NAMESPACE

Dialogamen::Dialogamen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogamen)
{
    ui->setupUi(this);
    ui->comboBox_mail->setModel(tmpfournisseur.afficher_email());


    ui->comboBox_ID_commande->setModel(tmpfournisseur.afficher());
    ui->comboBox_id_fournisseur->setModel(tmpmarchandise.afficher());
    ui->comboBox_numero_commande->setModel(tmpmarchandise.afficher());
    ui->comboBox_id_fournisseur_2->setModel(tmpcommande.afficher());
    ui->comboBox_numero_commande->setModel(tmpmarchandise.afficher_numero());
    ui->comboBox_produit_commande->setModel(tmpmarchandise.afficher_produit());
    ui->comboBox_ID_fournisseur->setModel(tmpfournisseur.afficher());
    ui->comboBox_TYPE_marchandise->setModel(tmpmarchandise.afficher());
    ui->comboBox_TYPE_marchandise_2->setModel(tmpmarchandise.afficher_type());

ui->comboBox_ID_fournisseur_modifier->setModel(tmpfournisseur.afficher());
ui->comboBox_ID_fournisseur->setModel(tmpfournisseur.afficher());
ui->comboBox_id_fournisseur_2->setModel(tmpcommande.afficher());
ui->tabfournisseur->setModel(tmpfournisseur.afficher());
ui->tabmarchandise->setModel(tmpmarchandise.afficher());
}

Dialogamen::~Dialogamen()
{
    delete ui;
}

void Dialogamen::on_pushButton_ajouter_fournisseur_clicked()
{   bool test;
    int id= ui->lineEdit_1->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    int num_telephone= ui->lineEdit_4->text().toInt();
    QString email=ui->lineEdit_5->text();

    if(nom==""|| prenom==""||id==0||id>99999999||nom.length()>10||num_telephone==0||tmpfournisseur.testemail(email)==false)


                {
                              QMessageBox::critical(nullptr, QObject::tr("vide"),
                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                              test=false;

                }
    else{
    fournisseur f(id,nom,prenom,num_telephone,email);
    N.notification_ajoutFournisseur();
     test=f.ajouter();}
     if(test)
     {
         ui->comboBox_mail->setModel(tmpfournisseur.afficher_email());
         ui->comboBox_ID_fournisseur->setModel(tmpfournisseur.afficher());
         ui->comboBox_ID_fournisseur_modifier->setModel(tmpfournisseur.afficher());
         ui->comboBox_id_fournisseur->setModel(tmpfournisseur.afficher());
         ui->comboBox_ID_commande->setModel(tmpfournisseur.afficher());
         ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                           QObject::tr("Fournisseur ajouté.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

         }
           else
               QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialogamen::on_pushButton_supprimer_fournisseur_clicked()
{
    int res1=ui->comboBox_ID_fournisseur->currentText().toInt();
            bool test=tmpfournisseur.supprimer(res1);
            N.notification_supprimerFournisseur();
            if(test)
            {   ui->comboBox_ID_fournisseur->setModel(tmpfournisseur.afficher());
                ui->tabfournisseur->setModel(tmpfournisseur.afficher());
                QMessageBox::information(nullptr, QObject::tr("Supprimer une fournisseur"),
                            QObject::tr("fournisseur supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}




void Dialogamen::on_pushButton_modifier_fournisseur_clicked()
{
          int id= ui->comboBox_ID_fournisseur_modifier->currentText().toInt();
          int num_telephone= ui->lineEdit_21->text().toInt();

        bool test=tmpfournisseur. modifier( id,num_telephone );
        N.notification_modifierFournisseur();
           if (test)
           {ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
               QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                           QObject::tr("Fournisseur modifié.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialogamen::on_pushButton_ajouter_marchandise_clicked()
{    bool test;
           QString type=ui->lineEdit_27->text();
           int quantite= ui->lineEdit_7->text().toInt();
           float prix= ui->lineEdit_8->text().toFloat();
           int numero= ui->lineEdit_35->text().toInt();
           QString produit=ui->lineEdit_28->text();
           if(type==""|| produit==""||quantite==0||numero==0||prix==0.0)


                       {
                                     QMessageBox::critical(nullptr, QObject::tr("vide"),
                                     QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                     test=false;

                       }
           else{

    marchandise m(type,quantite,prix,numero,produit);
    test=m.ajouter();}
     if(test)
     {   N.notification_ajoutMarchandise();
         ui->comboBox_numero_commande->setModel(tmpmarchandise.afficher_numero());
         ui->comboBox_produit_commande->setModel(tmpmarchandise.afficher_produit());
         ui->comboBox_TYPE_marchandise_2->setModel(tmpmarchandise.afficher_type());
         ui->comboBox_TYPE_marchandise->setModel(tmpmarchandise.afficher());
         ui->tabmarchandise->setModel(tmpmarchandise.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Ajouter un marchandise"),
                           QObject::tr("Marchandise ajouté.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

         }
           else
               QMessageBox::critical(nullptr, QObject::tr("Ajouter un marchandise"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialogamen::on_pushButton_modifier_marchandise_clicked()
{
          QString type= ui->comboBox_TYPE_marchandise_2->currentText();
          int quantite= ui->lineEdit_30->text().toInt();
          float prix= ui->lineEdit_31->text().toFloat();
          int numero= ui->lineEdit_36->text().toInt();
          QString produit=ui->lineEdit_37->text();



        bool test=tmpmarchandise.modifier(type,quantite,prix,numero,produit);
           if (test)
           {   N.notification_modifierMarchandise();
               ui->comboBox_TYPE_marchandise->setModel(tmpmarchandise.afficher());
               ui->tabmarchandise->setModel(tmpmarchandise.afficher());//refresh
               QMessageBox::information(nullptr, QObject::tr("Modifier un marchandise"),
                           QObject::tr("Marchandise modifié.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("Modifier un marchandise"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialogamen::on_pushButton_supprimer_marchandise_clicked()
{
    QString type=ui->comboBox_TYPE_marchandise->currentText();
        bool test=tmpmarchandise.supprimer(type);
        N.notification_supprimerMarchandise();
        if(test)
        {

            ui->comboBox_TYPE_marchandise->setModel(tmpmarchandise.afficher());
            ui->tabmarchandise->setModel(tmpmarchandise.afficher());//refresh

            QMessageBox::information(nullptr, QObject::tr("Supprimer marchandise"),
                        QObject::tr("marchandise supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer marchandise"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}






void Dialogamen::on_pushButton_ajouter_commande_clicked()
{   bool test;
    int id= ui->comboBox_id_fournisseur->currentText().toInt();
    int numero= ui->comboBox_numero_commande->currentText().toInt();
    int quantite= ui->lineEdit_42->text().toInt();
    QString produit=ui->comboBox_produit_commande->currentText();
    float prix_total= ui->lineEdit_44->text().toFloat();
    QString date=ui->dateEdit_45->text();

    if(date==""|| produit==""||id==0||numero==0||prix_total==0.0||quantite==0)


                {
                              QMessageBox::critical(nullptr, QObject::tr("vide"),
                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                              test=false;

                }
    else{



commande c(id,numero,quantite,produit,prix_total,date);
test=c.ajouter();}
if(test)
{  N.notification_ajoutCommande();
   ui->comboBox_id_fournisseur_2->setModel(tmpcommande.afficher());
   ui->comboBox_numero_commande->setModel(tmpmarchandise.afficher_numero());
   ui->comboBox_produit_commande->setModel(tmpmarchandise.afficher_produit());
   ui->comboBox_ID_commande->setModel(tmpfournisseur.afficher());
   ui->tabcommande->setModel(tmpcommande.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                    QObject::tr("Commande ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void Dialogamen::on_pushButton_modifier_commande_clicked()
{
    int id= ui->comboBox_id_fournisseur_2->currentText().toInt();
    int quantite= ui->lineEdit_29->text().toInt();
    float prix_total= ui->lineEdit_33->text().toFloat();
    QString date=ui->dateEdit_2->text();


  bool test=tmpcommande. modifier(id,quantite,prix_total,date);
     if (test)
     {   N.notification_modifierCommande();
         ui->comboBox_id_fournisseur_2->setModel(tmpcommande.afficher());
         ui->tabcommande->setModel(tmpcommande.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier une Commande"),
                     QObject::tr("Commande modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier une Commande"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}


void Dialogamen::on_pushButton_supprimer_commande_clicked()
{
    int res=ui->comboBox_ID_commande->currentText().toInt();
            bool test=tmpcommande.supprimer(res);
            if(test)
            {  N.notification_supprimerCommande();
                ui->comboBox_numero_commande->setModel(tmpmarchandise.afficher());
                ui->comboBox_produit_commande->setModel(tmpmarchandise.afficher());
                ui->comboBox_ID_commande->setModel(tmpfournisseur.afficher());
                ui->tabcommande->setModel(tmpcommande.afficher());
                QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                            QObject::tr("commande supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialogamen::on_pushButton_rechercher_fournisseur_clicked()
{
    int id;
    id=ui->lineEdit_13->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tabfournisseur->setModel(tmpfournisseur.rechercher(id));
}
}

void Dialogamen::on_pushButton_rechercher_marchandise_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery q;
        q.prepare("select * from MARCHANDISE where TYPE like '"+ui->lineEdit_14->text()+"' ");
        tmpmarchandise.rechercher_type(q) ;
        q.exec();
        model->setQuery(q);
        ui->tabmarchandise->setModel(tmpmarchandise.rechercher_type(q)) ;
}

void Dialogamen::on_pushButton_rechercher_commande_clicked()
{
    int id;

        id=ui->lineEdit_12->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabcommande->setModel(tmpcommande.rechercher(id));
}
}



void Dialogamen::on_radioButton_tri_fournisseur_clicked()
{
    ui->tabfournisseur->setModel( tmpfournisseur.afficher_tri());
}





void Dialogamen::on_radioButton_type_marchandise_clicked()
{
    ui->tabmarchandise->setModel( tmpmarchandise.afficher_tri_type());
}

void Dialogamen::on_radioButton_quantite_marchandise_clicked()
{
    ui->tabmarchandise->setModel( tmpmarchandise.afficher_tri_quantite());
}

void Dialogamen::on_radioButton_prix_marchandise_clicked()
{
    ui->tabmarchandise->setModel( tmpmarchandise.afficher_tri_prix());
}

void Dialogamen::on_radioButton_numero_marchandise_clicked()
{
    ui->tabmarchandise->setModel( tmpmarchandise.afficher_tri_numero());
}

void Dialogamen::on_radioButton_produit_marchandise_clicked()
{
    ui->tabmarchandise->setModel( tmpmarchandise.afficher_tri_produit());
}




void Dialogamen::on_radioButton_id_commande_clicked()
{
  ui->tabcommande->setModel( tmpcommande.afficher_tri_ID());
}

void Dialogamen::on_radioButton_numero_commande_clicked()
{
    ui->tabcommande->setModel( tmpcommande.afficher_tri_numero());
}

void Dialogamen::on_radioButton_quantite_commande_clicked()
{
    ui->tabcommande->setModel( tmpcommande.afficher_tri_quantite());
}

void Dialogamen::on_radioButton_produit_commande_clicked()
{
    ui->tabcommande->setModel( tmpcommande.afficher_tri_produit());
}

void Dialogamen::on_radioButton_prix_total_commande_clicked()
{
    ui->tabcommande->setModel( tmpcommande.afficher_tri_prix_total());
}

void Dialogamen::on_pushButton_imprimer_commande_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
               QPdfWriter pdf("C:/Users/Laptop/Desktop/amen/Pdf.pdf");
               QPainter painter(&pdf);
              int i = 4000;
                   painter.setPen(Qt::blue);
                   painter.setFont(QFont("Arial", 30));
                   painter.drawText(1100,1200,"Liste Des COMMANDES ");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 50));
                  // painter.drawText(1100,2000,afficheDC);
                   painter.drawRect(100,100,7300,2600);
                   //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial", 9));
                   painter.drawText(200,3300,"ID");
                   painter.drawText(1700,3300,"NUMERO");
                   painter.drawText(3200,3300,"QUANTITE");
                   painter.drawText(4900,3300,"PRODUIT");
                   painter.drawText(6600,3300,"PRIX_TOTAL");
                   painter.drawText(8100,3300,"DATED");
                   QSqlQuery query;
                   query.prepare("select * from COMMANDE");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(200,i,query.value(0).toString());
                       painter.drawText(1700,i,query.value(1).toString());
                       painter.drawText(3200,i,query.value(2).toString());
                       painter.drawText(4900,i,query.value(3).toString());
                       painter.drawText(6600,i,query.value(4).toString());
                       painter.drawText(8100,i,query.value(5).toString());
                      i = i + 500;
                   }
                   int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {
                           QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Laptop/Desktop/amen/Pdf.pdf"));
                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }


}



void Dialogamen::mailSent(QString status)
{
    if(status == "Message sent")
        N.mail_Fournisseur();
}


void Dialogamen::on_pushButton_Mail_clicked()
{
    Smtp* smtp = new Smtp("amen.benkhalifaaaaaa@gmail.com","amenamen1234","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("amen.benkhalifaaaaaa@gmail.com",ui->comboBox_mail->currentText(),ui->subject->text(),ui->msg->toPlainText());
}



void Dialogamen::on_pushButton_Statistique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                        model->setQuery("select * from COMMANDE where PRIX_TOTAL < 5 ");
                        float salaire=model->rowCount();
                        model->setQuery("select * from COMMANDE where PRIX_TOTAL  between 5 and 8 ");
                        float salairee=model->rowCount();
                        model->setQuery("select * from COMMANDE where PRIX_TOTAL>12 ");
                        float salaireee=model->rowCount();
                        float total=salaire+salairee+salaireee;
                        QString a=QString(" Commandes moins de 5 mois "+QString::number((salaire*100)/total,'f',2)+"%" );
                        QString b=QString(" Commandes entre 5 et 8 mois  "+QString::number((salairee*100)/total,'f',2)+"%" );
                        QString c=QString("Commandes +12 mois"+QString::number((salaireee*100)/total,'f',2)+"%" );
                        QPieSeries *series = new QPieSeries();
                        series->append(a,salaire);
                        series->append(b,salairee);
                        series->append(c,salaireee);
                if (salaire!=0)
                {QPieSlice *slice = series->slices().at(0);
                 slice->setLabelVisible();
                 slice->setPen(QPen());}
                if ( salairee!=0)
                {
                         // Add label, explode and define brush for 2nd slice
                         QPieSlice *slice1 = series->slices().at(1);
                         //slice1->setExploded();
                         slice1->setLabelVisible();
                }
                if(salaireee!=0)
                {
                         // Add labels to rest of slices
                         QPieSlice *slice2 = series->slices().at(2);
                         //slice1->setExploded();
                         slice2->setLabelVisible();
                }
                        // Create the chart widget
                        QChart *chart = new QChart();
                        // Add data to chart with title and hide legend
                        chart->addSeries(series);
                        chart->setTitle("Pourcentage Par Duree d'e promotion'commande des Fournisseurs :Nombre Des Commandes  "+ QString::number(total));
                        chart->legend()->hide();
                        // Used to display the chart
                        QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->resize(1000,500);
                        chartView->show();
}




