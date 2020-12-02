#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "conge.h"
#include <QMainWindow>
#include <QDialog>
#include "connection.h"
#include "smtp.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include "exportexcelobject.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSortFilterProxyModel *proxy_emp,*proxy_co;


void update_emp_list();

void show_tables();

private slots:


void on_Ajouter_Employe_clicked();

void on_supprimer_employe_clicked();

void on_tableView_activated(const QModelIndex &index);

void on_modifier_employe_clicked();



void sendMail();
void mailSent(QString);
void browse();

void on_tableView_clicked(const QModelIndex &index);

void on_comboBox_2_currentIndexChanged(int index);

void on_lineEdit_23_textChanged(const QString &arg1);

void on_lineEdit_26_textChanged(const QString &arg1);

void on_comboBox_5_currentIndexChanged(int index);

void on_tableView_3_clicked(const QModelIndex &index);

void on_pushButton_27_clicked();

void on_pushButton_clicked();

void on_pushButton_12_clicked();

void on_tableView_3_activated(const QModelIndex &index);

void on_pushButton_33_clicked();

private:
    Ui::MainWindow *ui;
        QStringList files;
    Employe tmpemploye;
    Conge tmpco;

    int id_emp=0,id_co=0,selcomemp=0,selcomco=0;

};
#endif // MAINWINDOW_H
