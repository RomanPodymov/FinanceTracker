//
//  registerscreen.hpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#ifndef REGISTER_SCREEN_H
#define REGISTER_SCREEN_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessQt/BackendlessAPI.hpp"

extern BackendlessAPI* api;

struct BackendlessRegisterUser: BasicBackendlessRegisterUser {
public:
    BackendlessRegisterUser(
        QString _email,
        QString _password,
        QString _name
    ): BasicBackendlessRegisterUser(_email, _password), name(_name) { }

    PostParams getAllParams() override {
        PostParams result = {{"name", new StringPostParam(name)}};
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
    BackendlessRegisterUserRepresentable* currentUser;
};

#endif
