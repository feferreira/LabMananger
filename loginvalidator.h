#ifndef LOGINVALIDATOR_H
#define LOGINVALIDATOR_H

#include <QObject>


/*!\class LoginValidator 
 * \brief Validação de Login
 * \todo usar arquivos para bla bla bla
 * e bla bla foo
 * \note isto é uma nota, use com cuidado
 * \warning presta atenção, de verdade.
 * 
 * consulta no banco de dados e valida o login
 */
class LoginValidator : public QObject
{
    Q_OBJECT
public:

    explicit LoginValidator(QObject *parent = nullptr);

    /*!\todo teste dessa merda
     * 
     * testando
     */
signals:
    /*!\brief Sinal de usuário válido
     * 
     * \param user nome de usuário
     */
    void userValid(QString user);
    void userValidated(bool isValid);

public slots:
    void slotValidateUser(QString user, QString pass);
};

#endif // LOGINVALIDATOR_H
