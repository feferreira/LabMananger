#ifndef SQLQUERY_H
#define SQLQUERY_H
#include <QObject>
#include <QSqlQuery>

class SqlQuery : public QObject
{
    Q_OBJECT

public:
    SqlQuery(QObject *parent = nullptr);
    QString selectLoginPassword(QString Login);
};

#endif // SQLQUERY_H
