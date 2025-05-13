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
    void* decode(QJsonObject obj) override {
        return new CustomSignIn(obj);
    }

    void write(QTextStream& stream, QString additionalToken) override {
        // stream << (additionalValue.isEmpty() ? userValue->userToken : additionalValue);
    }

    void* read(QTextStream& stream) override {
        auto result = new BackendlessSignInUser();
        stream >> result->userToken;
        return result;
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
        auto decoder = QSharedPointer<CustomSignInCoder>(new CustomSignInCoder());
        api->userAPI.signInUser(
            textFieldLogin.text(),
            textFieldPassword.text(),
            decoder
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
