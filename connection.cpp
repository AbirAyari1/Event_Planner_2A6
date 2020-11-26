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
    db.setDatabaseName("Source_CPP");
    db.setUserName("Ahmed");
    db.setPasseword("1111");

 bool ok=db.open();

    return ok;
}


void connection::closeConnection()
{db.close()};
