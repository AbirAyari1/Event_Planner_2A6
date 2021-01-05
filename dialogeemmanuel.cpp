#include "dialogeemmanuel.h"
#include "ui_dialogeemmanuel.h"
#include <QSqlQuery>
#include <QRegExpValidator>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QDate>
#include <QMessageBox>
#include "invites.h"
#include "table.h"
#include "invitation.h"
#include "smtpNgue.h"
#include <QFile>

#define NOM "^[a-zA-Z '.-]*$"
#define TEL "^[0-9]+$"
#define EMAIL "^[/w-/.]+@([/w-]+/.)+[/w-]{2,4}$"

DialogeEmmanuel::DialogeEmmanuel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogeEmmanuel)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    QRegExp rxEmail(EMAIL), rxNom(NOM), rxTel(TEL);
    QRegExpValidator * nom = new QRegExpValidator(rxNom,this);
    QRegExpValidator * tel = new QRegExpValidator(rxTel,this);
    QRegExpValidator * email = new QRegExpValidator(rxEmail,this);

    ui->lineEdit_nomInv->setValidator(nom);
    ui->lineEdit_prenomInv->setValidator(nom);
    ui->lineEdit_emailInv->setValidator(email);
    ui->lineEdit_telInv->setValidator(tel);

    ui->lineEdit_Nom_Mod_inv->setValidator(nom);
    ui->lineEdit_Prenom_Mod_inv->setValidator(nom);
    ui->lineEdit_Email_Mod_Inv->setValidator(email);
    ui->lineEdit_Tel_Mod_Inv->setValidator(tel);

    ui->comboBox_Ajouter_Table->addItem("Couple");
    ui->comboBox_Ajouter_Table->addItem("Famille");

    ui->comboBox_Modifier_Table->addItem("Couple");
    ui->comboBox_Modifier_Table->addItem("Famille");
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
     connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
}



DialogeEmmanuel::~DialogeEmmanuel()
{
    delete ui;
}


void DialogeEmmanuel::on_pushButton_ajoute_invite_clicked()
{
    QString nom, prenom, tel, email;
    nom = ui->lineEdit_nomInv->text();
    prenom = ui->lineEdit_prenomInv->text();
    tel = ui->lineEdit_telInv->text();
    email = ui->lineEdit_emailInv->text();
    if(nom.isEmpty()  || tel.isEmpty() ||email.isEmpty()){
       QMessageBox::information(this, "title","ces champs ne doivent pas être vide");

    }else{

    Invites invite( tel,  nom,  prenom ,  email) ;
    //int row = ui->tableInvite->setModel(Invite::afficherInvite());

    bool test = invite.ajouterInvite();

    if(test){

       // ui->tableInvite->setModel(Invites::afficherInvite());
        ui->tabWidget_2->setCurrentIndex(1);
        /*QMessageBox::information(nullptr, QObject::tr("Ajouter un Invité"),QObject::tr("Invité ajouter avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);*/
    }
    else {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Invité"),QObject::tr("Erreur!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
    }

}

void DialogeEmmanuel::on_tabWidget_2_tabBarClicked(int index)
{
    ui->tableInvite->setModel(tempInv.afficherInvite());
}

void DialogeEmmanuel::on_tableInvite_activated(const QModelIndex &index)
{
    QString val = ui->tableInvite->model()->data(index).toString();

    QSqlQuery query;
         query.prepare("Select * from INVITE where NOM_INVITE= '"+val+"' or PRENOM_INVITE ='"+val+"' or TEL_INVITE='"+val+"' or EMAIL_INVITE='"+val+"' ");
         if (query.exec())
              {
                  while(query.next())
                  {
                    ui->tabWidget_2->setCurrentIndex(2);
                    ui->lineEdit_Nom_Mod_inv->setText(query.value(1).toString());
                    ui->lineEdit_Prenom_Mod_inv->setText(query.value(2).toString());
                    ui->lineEdit_Tel_Mod_Inv->setText(query.value(3).toString());
                    ui->lineEdit_Email_Mod_Inv->setText(query.value(4).toString());
                  }
              }
              else
                  QMessageBox::critical(nullptr, QObject::tr("Erreur Database"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void DialogeEmmanuel::on_on_pushButton_ModInv_clicked_clicked()
{
    QString nom, prenom, tel, email;

    nom = ui->lineEdit_Nom_Mod_inv->text();
    prenom  = ui->lineEdit_Prenom_Mod_inv->text();
    tel = ui->lineEdit_Tel_Mod_Inv->text();
    email = ui->lineEdit_Email_Mod_Inv->text();

    if(nom.isEmpty()  || tel.isEmpty() ||email.isEmpty()){
       QMessageBox::information(this, "title","ces champs ne doivent pas être vide");

    }else {
        Invites inviteMod(tel,  nom,  prenom ,  email);

        bool test = inviteMod.modifierInvite(tel);
        if(test){
            ui->tableInvite->setModel(tempInv.afficherInvite()); //raffrechir la fenêtre d'affichage
            ui->tabWidget_2->setCurrentIndex(1);
            /*QMessageBox::information(nullptr, QObject::tr("Modifier un Invité"),QObject::tr("Invité Modifier avec succès!\n"
                                                                                             "click cancel to exit."), QMessageBox::Cancel);*/
        }
        else
            QMessageBox::information(nullptr, QObject::tr("Modifier un étudiant"),QObject::tr("Erreur!\n"
                                                                                             "click cancel to exit."), QMessageBox::Cancel);
}
}

void DialogeEmmanuel::on_on_pushButton_SupprInv_clicked_clicked()
{
    QString tel;
    tel = ui->lineEdit_Tel_Mod_Inv->text();

    bool test = tempInv.supprimerInvite(tel);
    if(test)
    {
        ui->tableInvite->setModel(tempInv.afficherInvite());
        ui->tabWidget_2->setCurrentIndex(1);

        /*QMessageBox::information(nullptr, QObject::tr("Supprimer un Invité"),QObject::tr("Invité supprimer avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);*/
    }
}

void DialogeEmmanuel::on_pushButton_filter_invite_clicked()
{
    QSqlQuery query;

        QSqlQueryModel *model=new QSqlQueryModel;
        query.prepare("Select * from INVITE order by NOM_INVITE ");
        query.prepare("Select * from INVITE order by PRENOM_INVITE ");
        query.exec();
        model->setQuery(query);
        ui->tableInvite->setModel(model);
}

void DialogeEmmanuel::on_pushButton_print_invite_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableInvite->model()->rowCount();
        const int columnCount = ui->tableInvite->model()->columnCount();
        QString TT = QDate::currentDate().toString("dd/MM/yyyy");
        out <<"<html>\n"
              "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << "<title>Wedny App<title>\n "
            << "</head>\n"
               "<img src=\"la_ferme.png\" height=400px width=400px; position=fixed; right=10px; top=10px; />"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> Liste des Invités du "+TT+"</strong></h1>"
            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
              "</br> </br>";
        // headers
        out << "<thead><tr bgcolor=#d6e5ff>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableInvite->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableInvite->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableInvite->isColumnHidden(column)) {
                    QString data =ui->tableInvite->model()->data(ui->tableInvite->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;
}

void DialogeEmmanuel::on_lineEdit_recherche_inv_textChanged(const QString &arg1)
{
    QString name = ui->lineEdit_recherche_inv->text();
        QSqlQuery query;
        QSqlQueryModel *model=new QSqlQueryModel;
        query.prepare("Select * from INVITE where NOM_INVITE like :test"); // c'est la recherche par nom uniquement
        query.prepare("Select * from INVITE where PRENOM_INVITE like :test");
        query.prepare("Select * from INVITE where  TEL_INVITE like :test1 or EMAIL_INVITE like :test1 or PRENOM_INVITE like :test1 "); // recherche multi criteres
        query.bindValue(":test", arg1+"%");
        query.bindValue(":test1", name+"%");
        query.exec();
        model->setQuery(query);
        ui->tableInvite->setModel(model); // pour le refesh de la table


        if (query.exec())
        {
            model->setQuery(query);
            ui->tableInvite->setModel(model); // pour le refresh de la table
        }
}

void DialogeEmmanuel::on_pushButton_ajouter_table_clicked()
{
    QString nomTable, typePlace;
    int nbPlace = 1;

    nomTable = ui->lineEdit_nom_table_ajouter->text();
    typePlace = ui->comboBox_Ajouter_Table->currentText();
    QString test1 ="Couple";
    QString test2 ="Famille";
    if(typePlace == test1)
        nbPlace = 2;
    else if(typePlace == test2)
        nbPlace = 4;


    Table tableEvent(nomTable, typePlace, nbPlace);
    //QMessageBox::information(this, "title",ui->comboBox_Ajouter_Table->currentText());

    bool test = tableEvent.ajouterTable();

    if(test){
        ui->tableEvent->setModel(tempTable.afficherTable());
        ui->tabWidget_2->setCurrentIndex(1);
        /*QMessageBox::information(nullptr, QObject::tr("Ajouter un Table"),QObject::tr("Table ajouter avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);*/
    }
    else {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Table"),QObject::tr("Erreur!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
}

void DialogeEmmanuel::on_tabWidget_3_tabBarClicked(int index)
{
    ui->tableEvent->setModel(tempTable.afficherTable());
}




void DialogeEmmanuel::on_tableEvent_activated(const QModelIndex &index)
{
    QString val = ui->tableEvent->model()->data(index).toString();

    QSqlQuery query;
         query.prepare("Select * from TABLE_EVENT where NOM_TABLE= '"+val+"' or TYPE_TABLE ='"+val+"' ");
         if (query.exec())
              {
                  while(query.next())
                  {
                    ui->tabWidget_3->setCurrentIndex(2);
                    ui->lineEdit_nom_mod_table1->setText(query.value(1).toString());

                  }
              }
              else
                  QMessageBox::critical(nullptr, QObject::tr("Erreur Database"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void DialogeEmmanuel::on_pushButton_ModTab_enregrs_clicked()
{
    QString nomTableMod, typeTableMod;
    int nbPlaceMod = 2;

    nomTableMod = ui->lineEdit_nom_mod_table1->text();
    typeTableMod = ui->comboBox_Modifier_Table->currentText();

    QString test1 ="Couple";
    QString test2 ="Famille";
    if(typeTableMod == test1)
        nbPlaceMod = 2;
    else if(typeTableMod == test2)
        nbPlaceMod = 4;

    Table tableEventMod(nomTableMod, typeTableMod,nbPlaceMod);
    bool test = tableEventMod.modifierTable(nomTableMod);

    if(test){
        ui->tableEvent->setModel(tempTable.afficherTable()); //raffrechir la fenêtre d'affichage
        ui->tabWidget_3->setCurrentIndex(1);
        /*QMessageBox::information(nullptr, QObject::tr("Modifier un Table"),QObject::tr("Table Modifier avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);*/
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Modifier un étudiant"),QObject::tr("Erreur!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
}

void DialogeEmmanuel::on_pushButton_suppr_table_clicked()
{
    QString nomTableSuppr = ui->lineEdit_nom_mod_table1->text();

    bool test = tempTable.supprimerTable(nomTableSuppr);
    if(test)
    {
        ui->tableEvent->setModel(tempTable.afficherTable());
        ui->tabWidget_3->setCurrentIndex(1);
        /*QMessageBox::information(nullptr, QObject::tr("Supprimer un Table"),QObject::tr("Table supprimer avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);*/
    }
}


void DialogeEmmanuel::browse()
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

void DialogeEmmanuel::sendMail()
{
    Smtp* smtp = new Smtp("emmanuelbenjamin.nguetoungoum@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       if( !files.isEmpty() )
           smtp->sendMail("emmanuelbenjamin.nguetoungoum@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
       else
           smtp->sendMail("emmanuelbenjamin.nguetoungoum@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
