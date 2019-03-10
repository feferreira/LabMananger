#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include <QObject>

class MysqlHelper : public QObject
{
    Q_OBJECT
public:
    explicit MysqlHelper(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYSQLHELPER_H