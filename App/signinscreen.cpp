//
//  signinscreen.cpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#include <QMessageBox>
#include "signinscreen.hpp"
#include "coordinator.hpp"

extern Coordinator* coordinator;

struct CustomSignIn: BackendlessSignInUser {
    QString someCustomField;

    CustomSignIn(
        QJsonObject jsonObject
    ): BackendlessSignInUser(jsonObject), someCustomField(jsonObject["someCustomField"].toString()) {

    }
};

class CustomSignInCoder: public SignInUserCoder {
    void* decode(QJsonObject obj) {
        return new CustomSignIn(obj);
    }
};

SignInScreen::SignInScreen(QWidget *parent): QWidget(parent),
    textFieldLogin(this), textFieldPassword(this), signInButton(this), registerButton(this) {
    layout.addWidget(&textFieldLogin);
    layout.addWidget(&textFieldPassword);
    layout.addWidget(&signInButton);
    layout.addWidget(&registerButton);
    signInButton.setText("Sign in");
    registerButton.setText("Register");
    QObject::connect(&signInButton, &QPushButton::clicked, this, [&]() {
        api->userAPI.signInUser(
            textFieldLogin.text(),
            textFieldPassword.text(),
            new CustomSignInCoder()
        );
    });
    QObject::connect(&registerButton, &QPushButton::clicked, this, [&]() {
        coordinator->openRegister();
    });
    QObject::connect(&api->userAPI, &BackendlessUserAPI::signInUserSuccess, this, [&]() {
        auto usr = api->userAPI.user();
        qDebug() << ((CustomSignIn*)usr)->someCustomField;

        coordinator->openAccounts();
    });
    QObject::connect(&api->userAPI, &BackendlessUserAPI::signInUserErrorBackendless, this, [&]() {
        coordinator->openError("Wrong credentials");
    });
    setLayout(&layout);
}

SignInScreen::~SignInScreen() {

}
