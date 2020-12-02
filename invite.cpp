#include "invite.h"
#include "ui_invite.h"
#include <QSqlQuery>
#include <QMessageBox>
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

Invite::Invite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Invite)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Invite::~Invite()
{
    delete ui;
}


//graphique

void Invite::on_pushButton_Ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Invite::on_pushButton_Afficher_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableInvite->setModel(Invite::afficherInvite());

}

void Invite::on_pushButton_Modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Invite::on_pushButton_Suppr_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Invite::on_pushButton_Home_clicked()
{
    emit homeCliked();
}



//fonctionnalités

/*Invite::Invite()
{
    this->telInvite ="";
    this->nomInvite ="";
    this->prenomInvite = "";
    this->emailInvite = "";
}*/


Invite::Invite(QString tel, QString nom, QString prenom , QString email)
{
    this->telInvite = tel;
    this->nomInvite = nom;
    this->prenomInvite = prenom;
    this->emailInvite = email;
}

QString Invite::getTelInvite(){
    return this->telInvite;
}

QString Invite::getNomInvite(){
    return this->nomInvite;
}

QString Invite::getPrenomInvite(){
    return this->prenomInvite;
}

QString Invite::getEmailInvite(){
    return this->emailInvite;
}

bool Invite::ajouterInvite(){
    QSqlQuery query;

    query.prepare("insert into INVITE (NOM_INVITE,PRENOM_INVITE,TEL_INVITE, EMAIL_INVITE) values (:nom, :prenom, :tel, :email)" );

    query.bindValue(":nom", this->nomInvite);
    query.bindValue(":prenom", this->prenomInvite);
    query.bindValue(":tel", this->telInvite);
    query.bindValue(":email", this->emailInvite);

return query.exec();

}

QSqlQueryModel * Invite:: afficherInvite(){
QSqlQueryModel* model = new QSqlQueryModel();
model->setQuery("select * from INVITE");

model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("TEL"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("EMAIL"));



return model;
}

bool Invite :: modifierInvite(QString tel){
    QSqlQuery query;

    query.prepare("update INVITE set  NOM_INVITE =:nom, PRENOM_INVITE =:prenom,TEL_INVITE = :tel, EMAIL_INVITE = :email  where   TEL_INVITE = :tel");

    query.bindValue(":tel", tel);
    query.bindValue(":nom", this->nomInvite);
    query.bindValue(":prenom", this->prenomInvite);
    query.bindValue(":email",this->emailInvite);

    return query.exec();
}

bool Invite :: supprimerInvite(QString tel){
    QSqlQuery query;

    query.prepare("delete from INVITE where TEL_INVITE = :tel");
    query.bindValue(":tel", tel);

    return query.exec();
}


void Invite::on_pushButton_ajoute_invite_clicked()
{
    QString nom, prenom, tel, email;
    nom = ui->lineEdit_nomInv->text();
    prenom = ui->lineEdit_prenomInv->text();
    tel = ui->lineEdit_telInv->text();
    email = ui->lineEdit_emailInv->text();

    Invite invite( tel,  nom,  prenom ,  email) ;
    //invite( tel,  nom,  prenom ,  email);

    bool test = invite.ajouterInvite();

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Invité"),QObject::tr("Invité ajouter avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Invité"),QObject::tr("Erreur!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }

}

void Invite::on_pushButton_4_clicked()
{
    QString tel;
    tel = ui->lineEdit_suppr_invite->text();

    bool test = Invite::supprimerInvite(tel);
    if(test)
    {
        ui->tableInvite->setModel(Invite::afficherInvite());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Invité"),QObject::tr("Invité supprimer avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
}


void Invite::on_pushButton_ModInv_clicked()
{
 QString nom, prenom, tel, email;

 nom = ui->lineEdit_Nom_Mod_inv->text();
 prenom  = ui->lineEdit_Prenom_Mod_inv->text();
 tel = ui->lineEdit_Tel_Mod_Inv->text();
 email = ui->lineEdit_Email_Mod_Inv->text();

 Invite inviteMod(tel,  nom,  prenom ,  email);

 bool test = inviteMod.modifierInvite(tel);
 if(test){
     ui->tableInvite->setModel(Invite::afficherInvite()); //raffrechir la fenêtre d'affichage
     QMessageBox::information(nullptr, QObject::tr("Modifier un Invité"),QObject::tr("Invité Modifier avec succès!\n"
                                                                                      "click cancel to exit."), QMessageBox::Cancel);
 }
 else
     QMessageBox::information(nullptr, QObject::tr("Modifier un étudiant"),QObject::tr("Erreur!\n"
                                                                                      "click cancel to exit."), QMessageBox::Cancel);
}

void Invite::on_lineEdit_textChanged(const QString &arg1)
{
    QString name = ui->lineEdit->text();
        QSqlQuery query;
        QSqlQueryModel *model=new QSqlQueryModel;
        query.prepare("Select * from INVITE where NOM_INVITE like :test"); // c'est la recherche par nom uniquement
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

void Invite::on_pushButton_filter_invite_clicked()
{
    QSqlQuery query;

        QSqlQueryModel *model=new QSqlQueryModel;
        query.prepare("Select * from INVITE order by NOM_INVITE");
        query.exec();
        model->setQuery(query);
        ui->tableInvite->setModel(model);
}

void Invite::on_pushButton_print_invite_clicked()
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
