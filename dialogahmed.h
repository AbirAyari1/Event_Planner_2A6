#ifndef DIALOGAHMED_H
#define DIALOGAHMED_H

#include "evenement.h"
#include "pack.h"
#include "service.h"
#include "connection.h"
#include<QSystemTrayIcon>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui

{
class Dialogahmed;
}
QT_END_NAMESPACE

class Dialogahmed : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogahmed(QWidget *parent = nullptr);
    ~Dialogahmed();

    QSortFilterProxyModel *proxy_eve,*proxy_pack,*proxy_serv;

    void update_emp_list();

    void show_tables();


private slots:
    void on_pushButton_valider_ajout_eve_clicked();

    void on_pushButton_supprimer_eve_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_modifier_eve_clicked();

    void on_tableView_4_clicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_comboBox_currentIndexChanged(int index);

    void on_id_liste_eve_textChanged(const QString &arg1);

    void on_id_pack1_textChanged(const QString &arg1);

    void on_id_serv_liste_textChanged(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_valider__ajout_pack_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_pushButton_valider_serv_ajout_clicked();

    void on_pushButton_supprimer_service_clicked();

    void on_tableView_4_activated(const QModelIndex &index);

    void on_pushButton_modifier_service_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialogahmed *ui;
    Evenement tmpevenement;
    Pack tmppack;
    service tmpservice;
    Evenement selection;

    int id_eve=0,id_pack=0,id_serv=0,selcomeve=0,selcompack=0,selcomserv=0;
};


#endif // DIALOGAHMED_H
