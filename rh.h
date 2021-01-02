#ifndef RH_H
#define RH_H
#include "employe.h"
#include "conge.h"
#include <QMainWindow>
#include <QDialog>
#include "connecxion.h"
#include "ui_mainwindow.h"
#include "smtp.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QFileDialog>
#include "exportexcelobject.h"
#include <QDialog>
#include <QTextToSpeech>
#include "client.h"

namespace Ui {
class rh;
}

class rh : public QDialog
{
    Q_OBJECT

public:
    explicit rh(QWidget *parent = nullptr);
    ~rh();
    QSortFilterProxyModel *proxy_emp,*proxy_co;
    void update_emp_list();

    void show_tables();

public slots:
    void appendMessage(const QString &from, const QString &message);

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
//chat
 void returnPressed();
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);

private:
    Ui::rh *ui;
    QStringList files;
Employe tmpemploye;
Conge tmpco;

int id_emp=0,id_co=0,selcomemp=0,selcomco=0;
Client client;
QString myNickName;
QTextTableFormat tableFormat;
 QTextToSpeech *m_speech;
};

#endif // RH_H
