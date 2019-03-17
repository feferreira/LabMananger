#include "mysqlhelper.h"
#include <QSqlDatabase>
#include <QDebug>

MysqlHelper::MysqlHelper(DbConfig &config, QObject *parent) : QObject(parent)
{
    db.setHostName(config.dbHost);
    db.setPassword(config.dbPassword);
    db.setUserName(config.dbUsername);
    db.setDatabaseName(config.dbName);
    if(db.open()){
        qDebug() << "db open sucessfully!";
    }
}
