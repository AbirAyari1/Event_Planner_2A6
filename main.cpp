#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
      w.show();
    Connection C;
    bool test=C.createConnection();

    if(test)
     {QMessageBox::information(nullptr,QObject::tr("database is open"),
                              QObject::tr("Connexion successful \n"
                                      "click OK to exit"), QMessageBox::Ok);}
    else
    {QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                             QObject::tr("Connexion failed \n"
                                     "click cancel to exit"), QMessageBox::Cancel);}



    return a.exec();
}
