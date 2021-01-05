#ifndef DIALOGASMA_H
#define DIALOGASMA_H
#include "salle.h"
#include "reservation.h"
#include <qdialog.h>
#include<qfiledialog.h>
#include <QMediaplayer>
#include <QTdebug>
#include <QDialog>

namespace Ui {
class DialogAsma;
}

class DialogAsma : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAsma(QWidget *parent = nullptr);
    ~DialogAsma();

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
    Ui::DialogAsma *ui;
    salle stmp;
    reservation rtmp;
    QStringList files;
     QMediaPlayer *player;
};

#endif // DIALOGASMA_H
