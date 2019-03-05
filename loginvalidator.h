#ifndef LOGINVALIDATOR_H
#define LOGINVALIDATOR_H

#include <QObject>

class LoginValidator : public QObject
{
    Q_OBJECT
public:
    explicit LoginValidator(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LOGINVALIDATOR_H