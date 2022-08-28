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

   // void addDataInAlbum(int index) const;
    void removeData(int id) const;


    std::unique_ptr<QSqlDatabase> UnitsDB;
    std::unique_ptr<QSqlQuery> query;

private:

};

#endif // DATABASEMANAGER_H
