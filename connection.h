#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDir>
#include <QFile>
#include "QSql"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include<QSqlDatabase>
#include<QSqlQuery>

class connection
{
public:
    connection();
               ~connection();
 bool create_connection();

};


#endif // CONNECTION_H
