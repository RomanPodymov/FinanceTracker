#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessAPI.hpp"

#ifndef REGISTER_SCREEN_H
#define REGISTER_SCREEN_H

extern BackendlessAPI* api;

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
