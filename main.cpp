#include "mainwindow.h"
#include <QApplication>
#include "QFile"
#include <QTextStream>
#include "connection.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFile f("C:/Users/ahmed/Documents/esprit2021/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
    connection c;
    if(c.create_connection())
        qDebug()<<"done";
     else qDebug()<<"error";
    MainWindow w;
    w.show();

    return a.exec();
}
