//
//  registerscreen.cpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#include <QMessageBox>
#include "registerscreen.hpp"
#include "coordinator.hpp"

extern Coordinator* coordinator;

RegisterScreen::RegisterScreen(QWidget *parent): QWidget(parent),
    textFieldLogin(this), textFieldPassword(this), registerButton(this) {
    layout.addWidget(&textFieldLogin);
    layout.addWidget(&textFieldPassword);
    layout.addWidget(&registerButton);
    registerButton.setText("Register");
    QObject::connect(&registerButton, &QPushButton::clicked, this, [&]() {
        delete currentUser;
        currentUser = new BackendlessRegisterUser(textFieldLogin.text(), textFieldPassword.text(), "name");
        api->userAPI.registerUser(*currentUser);
    });
    QObject::connect(&api->userAPI, &BackendlessUserAPI::registerUserResult, this, [&]() {
        coordinator->openSignIn();
    });
    setLayout(&layout);
}

RegisterScreen::~RegisterScreen() {
    delete currentUser;
}
