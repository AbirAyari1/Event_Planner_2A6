#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &inv);
    ui->stackedWidget->insertWidget(2, &invitation);
    ui->stackedWidget->insertWidget(3, &table);

    connect(&inv, SIGNAL(homeCliked()), this, SLOT(moveHome()));
    connect(&invitation, SIGNAL(homeCliked()), this, SLOT(moveHome()));
    connect(&table, SIGNAL(homeCliked()), this, SLOT(moveHome()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_invitation_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_table_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
