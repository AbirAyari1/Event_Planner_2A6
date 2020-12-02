#include "connexion.h"
#include "QSqlDatabase"


Connexion::Connexion()
{

}

bool Connexion::createConnect(){

    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A");
    db.setUserName("emmanuel");
    db.setPassword("esprit20");
    if (db.open())
    {
        test=true;
    }

    return  test;
}
