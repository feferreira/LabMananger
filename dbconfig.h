#ifndef DBCONFIG_H
#define DBCONFIG_H
#include <QString>

/*!\class DbConfig
 * \brief Configuração do banco de dados
 */
class DbConfig
{

public:
    QString dbHost; //! \var Hostname 
    QString dbName; //! \var Nome do banco
    QString dbUsername; //! \var Usuário 
    QString dbPassword; //! \var Senha
    /*!\brief Constrói modelo e inicializa atributos
     * \param[in] host Hostname
     * \param[in] name Nome do banco
     * \param[in] user Usuário 
     * \param[in] pass Senha
     */
    DbConfig(QString host, QString name, QString user, QString pass);
};

#endif // DBCONFIG_H
