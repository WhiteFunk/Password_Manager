#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>

class DatabaseManager
{
public:
    DatabaseManager();
    void DatabaseInit();

    QSqlDatabase GetDataBase ();


    std::unique_ptr<QSqlDatabase> UnitsDB;
    std::unique_ptr<QSqlQuery> query;

private:

};

#endif // DATABASEMANAGER_H
