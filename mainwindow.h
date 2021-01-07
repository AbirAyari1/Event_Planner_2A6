#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QSerialPort>
#include <QByteArray>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_39_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

 //   void on_confirmer_chan_mdp_clicked();

   // void on_tabWidget_currentChanged(int index);



   // void on_confirmer_langue_clicked();

   // void on_confirmer_theme_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

private:

    Ui::MainWindow *ui;
       QTranslator *translator=new QTranslator;
       QSerialPort *arduino;
           static const quint16 arduino_uno_vendor_id = 9025;
           static const quint16 arduino_uno_product_id = 67;
           QByteArray serialData;
               QString serialBuffer;
               QString parsed_data;
               int car_count;
           QString arduino_port_name;
           bool arduino_is_available;
    int counter;
};

#endif // MAINWINDOW_H
