#include "databasemanager.h"



DatabaseManager::DatabaseManager():
 UnitsDB(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
{

    UnitsDB->setDatabaseName("./unitsDB.db");
    if(UnitsDB->open()){qDebug("open");}

    DatabaseInit();

}

void DatabaseManager::DatabaseInit()
{

        query = std::make_unique<QSqlQuery>(*UnitsDB);
        query->exec("CREATE TABLE units(id INTEGER PRIMARY KEY AUTOINCREMENT,  Appication TEXT , Login TEXT, Password TEXT);" );
        qDebug("succes creation");

}

QSqlDatabase DatabaseManager::GetDataBase()
{
    return *UnitsDB;
}




