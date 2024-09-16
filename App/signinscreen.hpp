#ifndef SIGNIN_SCREEN_H
#define SIGNIN_SCREEN_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessAPI.hpp"

extern BackendlessAPI* api;

class SignInScreen: public QWidget {
    Q_OBJECT

public:
    SignInScreen(QWidget *parent = nullptr);
    ~SignInScreen();

private:
    QVBoxLayout layout;
    QLineEdit textFieldLogin;
    QLineEdit textFieldPassword;
    QPushButton signInButton;
    QPushButton registerButton;
};

#endif
