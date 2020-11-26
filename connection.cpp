#include "connection.h"
#include "QSqlDatabase"
#include <QSqlError>
#include <QSqlQuery>

Connection::Connection()
{

}


bool Connection::createConnection(){
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_CPP");
    db.setUserName("Abir");
    db.setPassword("esprit20");

bool ok = db.open();

    return ok;


}
void Connection::closeConnection()
{db.close();}
