#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessAPI.hpp"

#ifndef REGISTER_SCREEN_H
#define REGISTER_SCREEN_H

extern BackendlessAPI* api;

struct BackendlessRegisterUser: BasicBackendlessRegisterUser {
public:
    BackendlessRegisterUser(
        QString _email,
        QString _password,
        QString _name
    ): BasicBackendlessRegisterUser(_email, _password), name(_name) { }

    QMap<QString, QString> getAllParams() override {
        QMap<QString, QString> result = {{"name", name}};
        result.insert(BasicBackendlessRegisterUser::getAllParams());
        return result;
    }

protected:
    QString name;
};

class RegisterScreen: public QWidget
{
    Q_OBJECT

public:
    RegisterScreen(QWidget *parent = nullptr);
    ~RegisterScreen();

private:
    QVBoxLayout layout;
    QLineEdit textFieldLogin;
    QLineEdit textFieldPassword;
    QPushButton registerButton;
};

#endif
