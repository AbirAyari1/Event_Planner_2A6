#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");//inserer le nom de la source de données ODBC
db.setUserName("asma");//inserer nom de l'utilisateur
db.setPassword("asma007");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


else throw QString ("Erreur parametres"+test);



    return  test;
}
void Connection::fermerConnect()
{db.close();}

