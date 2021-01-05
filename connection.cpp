#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

connection::connection()
{

}


bool connection::createConnection()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("Ahmed");
    db.setPassword("1111");

 bool ok=db.open();

    return ok;
}


void connection::closeConnection()
{db.close();
}
