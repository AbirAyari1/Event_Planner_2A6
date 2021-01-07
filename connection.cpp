#include "connection.h"

connection::connection()
{
}
connection::~connection()
{
}
bool connection::create_connection()
{


    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");

    mydb.setDatabaseName("C:/Users/ahmed/Documents/try1/6jan 0135/pcr.db");



    if (mydb.open())
        return true;
    else return false;

}

