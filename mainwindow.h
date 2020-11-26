#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include "pack.h"
#include "service.h"
#include<QSystemTrayIcon>
#include <QMainWindow>


#include <QMainWindow>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    QPropertyAnimation *animation;

    void on_Statistique_eve_clicked();

    void on_pb_valider_ajout_evenement_clicked();

    void on_pb_valider_supp_eve_clicked();

    void on_pb_valider_modif_eve_clicked();

    void on_Rechercher_eve_clicked();

    void on_pb_valider_ajout_pack_clicked();

private:
    Ui::MainWindow *ui;
    Evenement tmpeve;
    Pack tmppack;
    Evenement tmprech;
    Pack tmpreche;
    QSystemTrayIcon * mysystem;

};
#endif // MAINWINDOW_H
