#include "dbconfig.h"

DbConfig::DbConfig(QString host, QString name, QString user, QString pass)
{
    dbHost = host;
    dbName = name;
    dbUsername = user;
    dbPassword = pass;
}
