#include "table.h"
#include "ui_table.h"
#include <QMessageBox>
#include <QSqlQuery>



Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox_Ajouter_Table->addItem("Couple");
    ui->comboBox_Ajouter_Table->addItem("Famille");

    ui->comboBox_Modifier_Table->addItem("Couple");
    ui->comboBox_Modifier_Table->addItem("Famille");

    //ui->comboBox_Ajouter_Table->setModel(tmp_inv.afficherNomInvite());
}

Table::~Table()
{
    delete ui;
}

Table::Table(QString nomTable, QString typeTable, int nbPlace){
    this->nomTable = nomTable;
    this->typeTable = typeTable;
    this->nbPlace = nbPlace;
}
void Table::on_pushButton_Home3_clicked()
{
    emit homeCliked();
}

void Table::on_pushButton_Ajouter_Table_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Table::on_pushButton_Afficher_Table_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableEvent->setModel(Table::afficherTable());
}

void Table::on_pushButton_Modifier_Table_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Table::on_pushButton_Supprimer_Table_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Table::on_pushButton_ajouter_table_clicked()
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


    Table tableEvent(nomTable, typePlace,nbPlace);
    //QMessageBox::information(this, "title",ui->comboBox_Ajouter_Table->currentText());

    bool test = tableEvent.ajouterTable();

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Table"),QObject::tr("Table ajouter avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Table"),QObject::tr("Erreur!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
}

QString Table::getNomTable(){
    return this->nomTable;
}


QString Table::getTypeTable(){
    return this->typeTable;
}

bool Table::ajouterTable(){

    QSqlQuery query;
    query.prepare("insert into TABLE_EVENT (NOM_TABLE, TYPE_TABLE, NOMBRE_PLACE) values (:nom, :type, :nbPlace) ");

    query.bindValue(":nom", this->nomTable);
    query.bindValue(":type", this->typeTable);
    query.bindValue(":nbPlace", this->nbPlace);

    return query.exec();
}

QSqlQueryModel * Table:: afficherTable(){
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("select * from TABLE_EVENT");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOMBRE PLACE"));

    return model;
}

//erreur dans la requette update
bool Table::modifierTable(QString nomTableMod){
    QSqlQuery query;

    query.prepare("update TABLE_EVENT set NOM_TABLE =:nom, TYPE_TABLE =:typeTable, NOMBRE_PLACE =:nbPlace where NOM_TABLE =:nom");

    query.bindValue(":nom", nomTableMod);
    query.bindValue(":typeTable", this->typeTable);
    query.bindValue(":nbPlace", this->nbPlace);

    return query.exec();
}

bool Table::supprimerTable(QString nomTableSuppr){
    QSqlQuery query;

    query.prepare("delete from TABLE_EVENT where NOM_TABLE =:nom");
    query.bindValue(":nom", nomTableSuppr);

    return query.exec();
}






void Table::on_pushButton_suppr_table_clicked()
{
    QString nomTableSuppr = ui->lineEdit_nom_table_suppr->text();

    bool test = Table::supprimerTable(nomTableSuppr);
    if(test)
    {
        ui->tableEvent->setModel(Table::afficherTable());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Table"),QObject::tr("Table supprimer avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
}

void Table::on_pushButton_3_clicked()
{
    QString nomTableMod, typeTableMod;
    int nbPlaceMod = 2;

    nomTableMod = ui->lineEdit_nom_mod_table->text();
    typeTableMod = ui->comboBox_Modifier_Table->currentText();

    QString test1 ="Couple";
    QString test2 ="Famille";
    if(typeTableMod == test1)
        nbPlace = 2;
    else if(typeTableMod == test2)
        nbPlace = 4;

    Table tableEventMod(nomTableMod, typeTableMod,nbPlaceMod);
    bool test = tableEventMod.modifierTable(nomTableMod);

    if(test){
        ui->tableEvent->setModel(Table::afficherTable()); //raffrechir la fenêtre d'affichage
        QMessageBox::information(nullptr, QObject::tr("Modifier un Table"),QObject::tr("Table Modifier avec succès!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Modifier un étudiant"),QObject::tr("Erreur!\n"
                                                                                         "click cancel to exit."), QMessageBox::Cancel);
}
