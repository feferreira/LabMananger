#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <dbconfig.h>

class QSqlDatabase;

/*! \class MysqlHelper
 *  \brief Comandos para o banco de dados
 */
class MysqlHelper : public QObject
{
    Q_OBJECT
    //!\brief armazena database em uso
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

public:
    /*!\brief Constrói novo objeto
     * \param[in] config configuração da conexão
     * \param[in] parent parent object 
     */
    explicit MysqlHelper(DbConfig& config, QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYSQLHELPER_H
