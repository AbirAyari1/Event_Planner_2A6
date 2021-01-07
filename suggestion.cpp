#include "suggestion.h"
#include<qDebug>
#include<QString>
#include<QSqlError>
#include<iostream>
#include<ostream>
#include"connection.h"
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QTime>
suggestion::suggestion( QString id_place, QString id_voiture,QString type_voit,QString nomprop,QString time)


{
    this->id_place=id_place;
    this->id_voiture=id_voiture;
     this->type_voit=type_voit;
this->nomprop=nomprop;
this->time=time;

}
bool suggestion::ajouter()
{

    QSqlQuery query;
                     query.prepare("INSERT INTO CARS VALUES (?,?,?,?,?)");
                    query.addBindValue(this->id_place);
                     query.addBindValue(this->id_voiture);


                    query.addBindValue(this->type_voit);
query.addBindValue(this->nomprop);
  query.addBindValue(this->time);
       return query.exec();

}
bool suggestion :: supprimer(QString id_voiture)
{
    QSqlQuery qry ;
    qry.prepare("delete from CARS where ID_VOITURE=?");
    qry.addBindValue(id_voiture);
    return qry.exec();

}

QSqlQueryModel* suggestion ::affichage(QString t)
{ if(t=="Serie"){
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *qr=new QSqlQuery();
    qr->prepare("SELECT * from CARS ORDER BY ID_VOITURE  ASC");//parcours table
   qr->exec();
   modal->setQuery(*qr);
    return modal;}
    else{QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *qr=new QSqlQuery();
        qr->prepare("SELECT * from CARS ORDER BY ID_PLACE  ASC");//parcours table
       qr->exec();
       modal->setQuery(*qr);
        return modal;}
}

bool suggestion::modifier(QString a,QString b,QString c,QString d,QString e)
{
 QSqlQuery q;
//Mettre à jour le nom

 q.prepare("UPDATE CARS set ID_VOITURE=:ID_VOITURE, TYPE_VOIT=:TYPE_VOIT,NOMPROP=:NOMPROP,TIME=:TIME where ID_PLACE='"+a+"'");
        q.bindValue(":ID_VOITURE",b);
        q.bindValue(":TYPE_VOIT",c);
        q.bindValue(":NOMPROP",d);
        q.bindValue(":TIME",e);

        return q.exec();

}

    QSqlQueryModel* suggestion::recherche(QString b)
    {
        QSqlQueryModel * modal=new QSqlQueryModel();
                QSqlQuery *qr=new QSqlQuery();
                qr->prepare("SELECT * from CARS where ID_VOITURE LIKE '%"+b+"%' or TYPE_VOIT  LIKE '%"+b+"%' or NOMPROP LIKE '%"+b+"%' or ID_PLACE LIKE '%"+b+"%'");  //parcours table
                qr->exec();
                modal->setQuery(*qr);
                return modal;
    }
    void suggestion::creerpdf()
    {
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM CARS ");
        q.exec();
        QString pdf="<br><img src='/C:/Users/ASUS/Documents/build-elaaqt-Desktop_Qt_5_9_9_MinGW_32bit-Debug/logo.png' height='42' width='144'/> <h1  style='color:pink'>tableau voitures  <br></h1>\n <br> <table>  <tr>  <th>ID_PLCAE</th> <th>ID_VOITURE </th>  <th>TYPE_VOIT </th> <th>NOMPROP</th>   </tr> " ;


        while ( q.next()) {
    pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" </td>   <td>"+q.value(3).toString()+"</td> <td>"+q.value(4).toString()+"<td> <td>"+q.value(5).toString()+" </td> <td> "+q.value(6).toString()+" </td> </td>";

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }


   /* void ParkingEcran::setBarriere1(int x )
    {    if(x==0)
        {
        ui->ParkingBarriere1->setVisible(true);
        ui->ParkingBarriere0->setVisible(false);
        }else
        {
            ui->ParkingBarriere1_2->setVisible(true);
            ui->ParkingBarriere0_2->setVisible(false);
        }
    }

    void ParkingEcran::update()
    {
        Parking p;
        int e =p.getEtatBarriere("E");
        int s=p.getEtatBarriere("S");

         if (e==0)
        {
            setBarriere0(0);
        }
         else setBarriere1(0);

         if (s==0)
        {
            setBarriere0(1);
        }
         else setBarriere1(1);
    }

*/
