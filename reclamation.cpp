#include "reclamation.h"
#include<qDebug>
#include<QString>
#include<QSqlError>
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QTime>
reclamation::reclamation(QString id_client,QString id_res,QString date_de_res,QString typer)

{   this->id_client=id_client;
    this->id_res=id_res;
    this->date_de_res=date_de_res;
 this->typer=typer;
}
bool reclamation::ajouter()
{

    QSqlQuery query;
                     query.prepare("INSERT INTO RECLAMATION VALUES (?,?,?,?)");
                     query.addBindValue(this->id_client);
                     query.addBindValue(this->id_res);

                     query.addBindValue(this->date_de_res);
                     query.addBindValue( this->typer);
       return query.exec();

}
bool reclamation :: supprimer(QString id_res)
{
    QSqlQuery qry ;
    qry.prepare("delete from RECLAMATION where ID_RES=?");
    qry.addBindValue(id_res);
    return qry.exec();

}



QSqlQueryModel* reclamation ::affichage(QString a)
{ if(a=="payement"){
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *qr=new QSqlQuery();
    qr->prepare("SELECT * from RECLAMATION ORDER BY TYPER  ASC");//parcours table
   qr->exec();
   modal->setQuery(*qr);
    return modal;}
    else{QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *qr=new QSqlQuery();
        qr->prepare("SELECT * from RECLAMATION ORDER BY DATE_DE_RES  ASC");//parcours table
       qr->exec();
       modal->setQuery(*qr);
        return modal;}
}
bool reclamation::modifier(QString a,QString b,QString c,QString d)
{
 QSqlQuery q;
//Mettre à jour le nom

 q.prepare("UPDATE RECLAMATION set ID_RES=:ID_RES, DATE_DE_RES=:DATE_DE_RES,TYPER=:TYPER where ID_CLIENT='"+a+"'");
        q.bindValue(":ID_RES",b);
        q.bindValue(":DATE_DE_RES",c);
        q.bindValue(":TYPER",d);
        return q.exec();

}

    QSqlQueryModel* reclamation::recherchereclamation(QString b)
    {
        QSqlQueryModel * modal=new QSqlQueryModel();
                QSqlQuery *qr=new QSqlQuery();
                qr->prepare("SELECT * from RECLAMATION where ID_RES LIKE '%"+b+"%' or DATE_DE_RES LIKE '%"+b+"%' or TYPER LIKE '%"+b+"%' or ID_CLIENT LIKE '%"+b+"%'");  //parcours table
                qr->exec();
                modal->setQuery(*qr);
                return modal;
    }



    void reclamation::creerpdf()
    {
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM RECLAMATION ");
        q.exec();
        QString pdf="<br><img src='/C:/Users/ASUS/Documents/build-elaaqt-Desktop_Qt_5_9_9_MinGW_32bit-Debug/logo.png' height='42' width='144'/> <h1  style='color:pink'>tableau reservations  <br></h1>\n <br> <table>  <tr>  <th>ID_CLIENT</th> <th>DATE_DE_RES </th>  <th>TYPER</th> </tr> " ;


        while ( q.next()) {
    pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" </td>   <td>"+q.value(3).toString()+"</td> <td>"+q.value(4).toString()+"<td> <td>"+q.value(5).toString()+" </td> <td> "+q.value(6).toString()+" </td> </td>";

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }
