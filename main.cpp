#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion con;
        bool test = con.createConnect();

        if(test)
            {
               /* QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("connection successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    w.show();
    return a.exec();
}
