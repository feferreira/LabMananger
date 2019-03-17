#ifndef DBCONFIG_H
#define DBCONFIG_H
#include <QString>

class DbConfig
{

public:
    QString dbHost;
    QString dbName;
    QString dbUsername;
    QString dbPassword;
    DbConfig(QString host, QString name, QString user, QString pass);
};

#endif // DBCONFIG_H
