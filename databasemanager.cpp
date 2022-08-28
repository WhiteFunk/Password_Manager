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

//void DatabaseManager::addPictureInAlbum(int albumId, Picture& picture) const
//{
//    QSqlQuery query(mDatabase);
//    query.prepare(QString("INSERT INTO pictures")
//        + " (album_id, url)"
//        + " VALUES ("
//        + ":album_id, "
//        + ":url"
//        + ")");
//    query.bindValue(":album_id", albumId);
//    query.bindValue(":url", picture.fileUrl());
//    query.exec();
//    DatabaseManager::debugQuery(query);
//    picture.setId(query.lastInsertId().toInt());
//    picture.setAlbumId(albumId);
//}

void DatabaseManager::removeData(int id) const
{
    query->prepare("DELETE FROM units WHERE id = (:id)");
    query->bindValue(":id", id);
    query->exec();
}

