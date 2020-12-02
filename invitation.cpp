#include "invitation.h"
#include "ui_invitation.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QAbstractItemModel >
#include <QMap>


Invitation::Invitation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Invitation)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);


}

Invitation::~Invitation()
{
    delete ui;
}

void Invitation::on_pushButton_Home2_clicked()
{
    emit homeCliked();
}

void Invitation::on_pushButton_Ajouter_Invitation_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox_personnes_ajouter->setModel(Invitation::afficherNomInvite());
    ui->comboBox_tables_ajouter->setModel(Invitation::afficherNomTable());

    //QSqlQueryModel* model = new QSqlQueryModel();

    //QMessageBox::information(this, "title",ui->comboBox_Ajouter_Table->currentText());
    //QDebug <<ui->comboBox_Ajouter_Table->currentText();
}

void Invitation::on_pushButton_Afficher_Invitation_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void Invitation::on_pushButton_Modifier_Invitation_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Invitation::on_pushButton_Supprimer_Invitation_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

Invitation::Invitation(int idInvite, int idTable, int positionInviteTable){
    this->idInvite = idInvite;
    this->idTable = idTable;
    this->positionInviteTable = positionInviteTable;
}

int Invitation::getIdITable(){
    return this->idTable;
}

int Invitation::getIdInvitation(){
    return this->idInvite;
}

int Invitation::getPositionInviteTable(){
    return this->positionInviteTable;
}

bool Invitation::ajouterInvitation(){
QSqlQuery query;

query.prepare("insert into INVITATION (ID_INVITE, ID_TABLE, POSITION) values (ID_INVITE = :idInvite, ID_TABLE = :idTable, POSITION = :positionInviteTable) ");

query.bindValue(":idInvite",this->idInvite);
query.bindValue(":idTable",this->idTable);
query.bindValue(":positionInviteTable",this->positionInviteTable);

return query.exec();
}

bool Invitation::modifierInvitation(int idInvite){

    QSqlQuery query;

    query.prepare("update INVITATION set (ID_INVITE, ID_TABLE, POSITION) values (ID_INVITE = :idInvite, ID_TABLE = :idTable, POSITION = :positionInviteTable) where ID_INVITE = :idInvite");

    query.bindValue(":idInvite",idInvite);
    query.bindValue(":idTable",this->idTable);
    query.bindValue(":positionInviteTable",this->positionInviteTable);

    return query.exec();
}

bool Invitation::supprimerInvitation(int idInvite){
    QSqlQuery query;

    query.prepare("delete from INVITATION where ID_INVITE = :idInvite");
    query.bindValue(":idInvite", idInvite);

    return query.exec();
}

QSqlQueryModel * Invitation:: afficherNomInvite(){

QSqlQueryModel* model = new QSqlQueryModel();
model->setQuery("select NOM_INVITE, TEL_INVITE  from INVITE");

return model;
}

QSqlQueryModel * Invitation:: afficherNomTable(){

QSqlQueryModel* model = new QSqlQueryModel();
model->setQuery("select NOM_TABLE from TABLE_EVENT");

return model;
}





void Invitation::on_comboBox_personnes_ajouter_currentIndexChanged(const QString &arg1)
{
    //QAbstractItemModel * model = ui->comboBox_personnes_ajouter->model();



   // QMessageBox::information(this, "title",ui->comboBox_personnes_ajouter->currentData());
}
