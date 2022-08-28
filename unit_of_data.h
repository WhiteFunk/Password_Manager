#ifndef UNITOFDATA_H
#define UNITOFDATA_H

#include <QString>

class UnitOfData
{
public:
    UnitOfData();

    QString AppName;
    void SetAppName(QString name);
    QString GetAppName ();

    QString Login;
    void SetLogin(QString name);
    QString GetLogin ();

    QString Password;
    void SetPassword(QString name);
    QString GetPassword ();

};

#endif // UNITOFDATA_H
