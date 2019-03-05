#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT
    QString *user = nullptr;
public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void validateUser(QString user, QString pass);

private slots:
    void on_exitButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
