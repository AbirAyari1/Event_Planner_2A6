
#include <QMessageBox>
#include <QString>
#include <QLineEdit>
#include "evenement.h"
#include "pack.h"
#include "service.h"
#include <QDebug>
#include<QSystemTrayIcon>
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "ui_dialogahmed.h"
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
#include "dialogahmed.h"

QT_CHARTS_USE_NAMESPACE

DialogAhmed::DialogAhmed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAhmed)

{       ui->setupUi(this);
        //Connection C;
        //C.createConnection();

        show_tables();
        update_eve_list();

}

DialogAhmed::~DialogAhmed()
{
    delete ui;
}

void DialogAhmed::on_pushButton_valider_ajout_eve_clicked()
{
    int idevenement= ui->id_eve->text().toInt();
    QString nomevenement= ui->nom_eve->text();
    QString typeevenement= ui->type_eve->currentText();
    int prixevenement= ui->prix_eve->text().toInt();
    int tempsevenement= ui->temps_eve->text().toInt();

    Evenement ev(idevenement, nomevenement, typeevenement, prixevenement, tempsevenement);

    bool test=ev.ajouter();
    if(test)
    {
        show_tables();
        QMessageBox::information(nullptr,QObject::tr("Ajouer Evenement"),
                                 QObject::tr("Evenement ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }
        update_eve_list();
}


void DialogAhmed::on_pushButton_supprimer_eve_clicked()

{
          bool test=tmpevenement.supprimer(id_eve);
         if (test)
         {
             show_tables();
          QMessageBox::information(nullptr,QObject::tr("Supprimer evenement"),
                                   QObject::tr("Evenement supprimé.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
         }

         update_eve_list();

}

void DialogAhmed::on_tableView_activated(const QModelIndex &index)

    { QString val=ui->tableView->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from EVENEMENT where"
                  " IDEVENEMENT='"+val+"' " );
      if(qry.exec())
        {while (qry.next())
       {
         ui->modif_id->setText(qry.value(0).toString());
         ui->nom_modif_eve->setText(qry.value(1).toString());
         ui->type_modif_eve->setCurrentText(qry.value(2).toString());
         ui->prix_modif_eve->setText(qry.value(3).toString());
         ui->temps_modif_eve->setText(qry.value(4).toString());
          }
    }
    }


void DialogAhmed::on_pushButton_modifier_eve_clicked()
{
    {

        int idevenement=ui->modif_id->text().toInt();
        QString nomevenement=ui->nom_modif_eve->text();
        QString typeevenement=ui->type_modif_eve->currentText();
        int prixevenement=ui->prix_modif_eve->text().toInt();
        int tempsevenement=ui->temps_modif_eve->text().toInt();
        Evenement ev(idevenement,nomevenement,typeevenement,prixevenement,tempsevenement);
        bool test=ev.modifier();
        if (test)
        {
            show_tables();
        QMessageBox::information(nullptr,QObject::tr("Modification Evenement"),
                                 QObject::tr("Evenement modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }


    }
}

//affichage + metier tri
void DialogAhmed::show_tables()
{
    //evenement
//creation model (masque du tableau) : permet recherche et tri
    proxy_eve = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy_eve->setSourceModel(tmpevenement.afficher());

 //pour la recherche
    proxy_eve->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy_eve->setFilterKeyColumn(selcomeve); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableView->setModel(proxy_eve);

    //pack

    //creation model (masque du tableau) : permet recherche et tri
        proxy_pack = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_pack->setSourceModel(tmppack.afficher());

     //pour la recherche
        proxy_pack->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
        proxy_pack->setFilterKeyColumn(selcompack); // chercher dans tout le tableau (-1) ou donner le numero de la colone
       //remplissage tableau avec le masque
        ui->tableView_3->setModel(proxy_pack);

        //service

        //creation model (masque du tableau) : permet recherche et tri
            proxy_serv = new QSortFilterProxyModel();

         //definir la source (tableau original)
            proxy_serv->setSourceModel(tmpservice.afficher());

         //pour la recherche
            proxy_serv->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
            proxy_serv->setFilterKeyColumn(selcomserv); // chercher dans tout le tableau (-1) ou donner le numero de la colone
           //remplissage tableau avec le masque
            ui->tableView_4->setModel(proxy_serv);
}


void DialogAhmed::on_tableView_4_clicked(const QModelIndex &index)
{
    id_serv=ui->tableView_4->model()->data(index).toInt();
}

void DialogAhmed::on_tableView_clicked(const QModelIndex &index)
{
    id_eve=ui->tableView->model()->data(index).toInt();
}



//recherche dynamique

void DialogAhmed::on_id_liste_eve_textChanged(const QString &arg1)
{
    proxy_eve->setFilterFixedString(arg1);
}

void DialogAhmed::on_id_pack1_textChanged(const QString &arg1)
{
    proxy_pack->setFilterFixedString(arg1);
}

void DialogAhmed::on_id_serv_liste_textChanged(const QString &arg1)
{
    proxy_serv->setFilterFixedString(arg1);
}


void DialogAhmed::on_pushButton_9_clicked()
{
    bool test=tmppack.supprimer(id_pack);
   if (test)
   {
       show_tables();
    QMessageBox::information(nullptr,QObject::tr("Supprimer pack"),
                             QObject::tr("pack supprimé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
   }


}

void DialogAhmed::on_pushButton_valider__ajout_pack_clicked()
{
    int idpack= ui->id_pack->text().toInt();
    QString nompack= ui->nom_pack->text();
    QString typepack= ui->type_pack->currentText();
    int ideve=ui->id_eve_2->currentText().toInt();

    Pack pc(idpack, nompack, typepack,ideve);

    bool test=pc.ajouter();
    if(test)
    {
        show_tables();

        ui->id_pack->clear();
        ui->type_pack->setCurrentIndex(0);
        ui->id_eve_2->setCurrentIndex(0);

    QMessageBox::information(nullptr,QObject::tr("Ajouer Pack"),
                             QObject::tr("Pack ajouté.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
    }

}



void DialogAhmed::on_tableView_3_activated(const QModelIndex &index)
{
    { QString val=ui->tableView_3->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from Pack where"
                  " IDPACK='"+val+"' " );
      if(qry.exec())
        {while (qry.next())
       {
         ui->modif_pack_id->setText(qry.value(0).toString());
         ui->nom_modif_pack->setText(qry.value(1).toString());
         ui->comboBox_2->setCurrentText(qry.value(2).toString());
         ui->comboBox->setCurrentText(qry.value(3).toString());
          }
    }
    }
}

void DialogAhmed::update_eve_list(){
    QSqlQueryModel *m=new QSqlQueryModel();
    QSqlQuery *querry=new QSqlQuery();
    querry->prepare("SELECT idevenement FROM EVENEMENT");
    querry->exec();
    m->setQuery(*querry);

    ui->id_eve_2->setModel(m);
    ui->comboBox->setModel(m);
}

void DialogAhmed::on_pushButton_8_clicked()
{
    {

        int idpack=ui->modif_pack_id->text().toInt();
        QString nompack=ui->nom_modif_pack->text();
        QString typepack=ui->comboBox_2->currentText();
        int ideve=ui->comboBox->currentText().toInt();

        Pack pc(idpack,nompack,typepack,ideve);
        bool test=pc.modifier();
        if (test)
        {
            show_tables();
        QMessageBox::information(nullptr,QObject::tr("Modification Pack"),
                                 QObject::tr("Pack modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }


    }
}

void DialogAhmed::on_tableView_3_clicked(const QModelIndex &index)
{
    id_pack=ui->tableView_3->model()->data(index).toInt();
}

void DialogAhmed::on_pushButton_valider_serv_ajout_clicked()
{

    int idservice= ui->id_service->text().toInt();
    QString nomservice= ui->nom_service->text();
    QString cathservice= ui->cath_service->text();
    int prixservice= ui->prix_service->text().toInt();


    service sv(idservice, nomservice, cathservice, prixservice);

    bool test=sv.ajouter();
    if(test)
    {
        show_tables();
    QMessageBox::information(nullptr,QObject::tr("Ajouter Service"),
                             QObject::tr("Service ajouté.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
    }


}




void DialogAhmed::on_pushButton_supprimer_service_clicked()
{
    bool test=tmpservice.supprimer(id_serv);
   if (test)
   {
       show_tables();
    QMessageBox::information(nullptr,QObject::tr("Supprimer service"),
                             QObject::tr("service supprimé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
   }
}



void DialogAhmed::on_tableView_4_activated(const QModelIndex &index)
{
    { QString val=ui->tableView_4->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from Service where"
                  " IDSERVICE='"+val+"' " );
      if(qry.exec())
        {while (qry.next())
       {
         ui->modif_id_serv->setText(qry.value(0).toString());
         ui->nom_modif_serv->setText(qry.value(1).toString());
         ui->cath_modif_serv->setText(qry.value(2).toString());
         ui->prix_modif_serv->setText(qry.value(3).toString());
          }
    }
    }
}




void DialogAhmed::on_pushButton_modifier_service_clicked()
{
    {

        int idservice=ui->modif_id_serv->text().toInt();
        QString nomservice=ui->nom_modif_serv->text();
        QString cathservice=ui->cath_modif_serv->text();
        int prixservice=ui->prix_modif_serv->text().toInt();
        service sv(idservice,nomservice,cathservice,prixservice);
        bool test=sv.modifier();
        if (test)
        {
            show_tables();
        QMessageBox::information(nullptr,QObject::tr("Modification Service"),
                                 QObject::tr("Service modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }


    }
}

void DialogAhmed::on_pushButton_clicked()
{



//    QBarSet *set0=new QBarSet("Anniversaire");
//    QBarSet *set1=new QBarSet("Soiree");
//    QBarSet *set2=new QBarSet("Mariage");
//    QBarSet *set3=new QBarSet("fête");

//    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
//    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
//    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
//    *set3 << 248 << 244 << 265 << 281 << 278 << 313;

//    QBarSeries *series = new QBarSeries();
//    series->append(set0);
//    series->append(set1);
//    series->append(set2);
//    series->append(set3);

//    QChart *chart = new QChart();
//    chart->addSeries(series);
//    chart->setTitle("nombre de selection par année");
//    //NoAnimation, GridAxisAnimations, SeriesAnimation
//    chart->setAnimationOptions(QChart::AllAnimations);
//    QStringList categories;
//    categories <<"2015" <<"2016" <<"2017" << "2018" <<"2019" <<"2020";
//    QBarCategoryAxis *axis = new QBarCategoryAxis();
//    axis->append(categories);
//    chart->createDefaultAxes();
//    chart->setAxisX(axis, series);
//    chart->legend()->setVisible(true);
//    chart->legend()->setAlignment(Qt::AlignBottom);
//    QChartView *chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);
//    QPalette pal=qApp->palette();
//    pal.setColor(QPalette::Window, QRgb(0xffffff));
//    pal.setColor(QPalette::WindowText, QRgb(0x404040));
//    qApp->setPalette(pal);

//}

//{
//    QPieSeries *series = new QPieSeries();
//    series->append("Anniversaire", .30);
//    series->append("Fete", .20);
//    series->append("Soiree", .10);
//    series->append("Mariage", .40);

//    QPieSlice *slice0=series->slices().at(0);
//    slice0->setLabelVisible();

//    QPieSlice *slice1=series->slices().at(1);
//    slice1->setExploded();
//    slice1->setLabelVisible();
//    slice1->setPen(QPen(Qt::darkGreen, 2));
//    slice1->setBrush(Qt::green);

//    QPieSlice *slice2=series->slices().at(2);
//    slice2->setLabelVisible();
//    QPieSlice *slice3=series->slices().at(3);
//    slice3->setLabelVisible();

//    QChart *chart= new QChart();
//    chart->addSeries(series);
//    chart->setTitle("Evenement");
//    chart->legend()->hide();


//    QChartView *chartView= new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);

//    QMainWindow window;

//    window.setCentralWidget(chartView);
//    window.resize(420,300);
//    window.show();

//    s = new stat_combo();

//  s->setWindowTitle("statistique ComboBox");
//  s->choix_pie();
//  s->show();


    QSqlQueryModel * model= new QSqlQueryModel();
                            model->setQuery("select * from EVENEMENT where TYPEEVENEMENT='Soiree'");
                            int soiree=model->rowCount();
                            model->setQuery("select * from EVENEMENT where TYPEEVENEMENT='Mariage'");
                            float mariage=model->rowCount();
                            model->setQuery("select * from EVENEMENT where TYPEEVENEMENT='Anniversaire'");
                            float anniversaire=model->rowCount();
                            model->setQuery("select * from EVENEMENT where TYPEEVENEMENT='Fete'");
                            int fete=model->rowCount();
                            float total=soiree+mariage+anniversaire+fete;
                            QString a=QString(" Nombre de soiree "+QString::number((soiree*100)/total,'f',2)+"%" );
                            QString b=QString(" Nombre de mariage "+QString::number((mariage*100)/total,'f',2)+"%" );
                            QString c=QString("Nombre d'anniversaire"+QString::number((anniversaire*100)/total,'f',2)+"%" );
                            QString d=QString("Nombre de fete"+QString::number((fete*100)/total,'f',2)+"%" );
                            QPieSeries *series = new QPieSeries();
                            series->append(a,soiree);
                            series->append(b,mariage);
                            series->append(c,anniversaire);
                            series->append(d,fete);
                    if (soiree!=0)
                    {QPieSlice *slice = series->slices().at(0);
                     slice->setLabelVisible();
                     slice->setPen(QPen());}
                    if ( mariage!=0)
                    {
                             // Add label, explode and define brush for 2nd slice
                             QPieSlice *slice1 = series->slices().at(1);
                             //slice1->setExploded();
                             slice1->setLabelVisible();
                    }
                    if(anniversaire!=0)
                    {
                             // Add labels to rest of slices
                             QPieSlice *slice2 = series->slices().at(2);
                             //slice1->setExploded();
                             slice2->setLabelVisible();
                    }
                    if(fete!=0)
                    {
                             // Add labels to rest of slices
                             QPieSlice *slice3 = series->slices().at(3);
                             //slice1->setExploded();
                             slice3->setLabelVisible();
                    }
                            // Create the chart widget
                            QChart *chart = new QChart();
                            // Add data to chart with title and hide legend
                            chart->addSeries(series);
                            chart->setTitle("Pourcentage de type evenement  "+ QString::number(total));
                            chart->legend()->hide();
                            // Used to display the chart
                            QChartView *chartView = new QChartView(chart);
                            chartView->setRenderHint(QPainter::Antialiasing);
                            chartView->resize(1000,500);
                            chartView->show();
}




