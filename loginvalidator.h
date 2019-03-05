#ifndef LOGINVALIDATOR_H
#define LOGINVALIDATOR_H

#include <QObject>

class LoginValidator : public QObject
{
    Q_OBJECT
public:
    explicit LoginValidator(QObject *parent = nullptr);

signals:
    void userValid(QString user);
    void userValidated(bool isValid);

public slots:
    void slotValidateUser(QString user, QString pass);
};

#endif // LOGINVALIDATOR_H
