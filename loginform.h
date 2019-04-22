#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LoginForm;
}
class QKeyEvent;

class LoginForm : public QWidget
{
    Q_OBJECT
    QString *user = nullptr;
public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void signalValidateUser(QString user, QString pass);

public slots:
    void userIsValid(bool isValid);

private slots:
    void on_exitButton_clicked();
    void on_loginButton_clicked();
    void on_userInput_textEdited(const QString &arg1);

private:
    void keyPressEvent(QKeyEvent *event);
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
