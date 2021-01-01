#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "salle.h"
#include <QMainWindow>
#include "reservation.h"
#include <qdialog.h>
#include<qfiledialog.h>
#include <QMediaplayer>
#include <QTdebug>



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

    void on_pb_ajouter_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_15_clicked();
    void sendMail();
    void mailSent(QString);
    void browse();


private:
    Ui::MainWindow *ui;
   salle stmp;
   reservation rtmp;
   QStringList files;
    QMediaPlayer *player;
};
#endif // MAINWINDOW_H
