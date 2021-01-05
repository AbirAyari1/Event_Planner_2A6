#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connecxion.h"
#include <QDebug>
#include "employe.h"
#include "accesscard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString user() const ;
 //QString userID;
 private slots:
    void update_label(); //
    void on_pushButton_submit_clicked();



    void on_pushButton_submit_2_clicked();

private:
    Ui::MainWindow *ui;
    AccessCard A;
    QByteArray data;
    QString id;
     int e;
};
#endif // MAINWINDOW_H
