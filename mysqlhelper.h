#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <dbconfig.h>

class QSqlDatabase;

class MysqlHelper : public QObject
{
    Q_OBJECT
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

public:
    explicit MysqlHelper(DbConfig& config, QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYSQLHELPER_H
