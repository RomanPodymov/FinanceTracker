#include <QMessageBox>
#include "signinscreen.hpp"
#include "coordinator.hpp"

extern Coordinator* coordinator;

SignInScreen::SignInScreen(QWidget *parent): QWidget(parent),
    textFieldLogin(this), textFieldPassword(this), signInButton(this), registerButton(this) {
    layout.addWidget(&textFieldLogin);
    layout.addWidget(&textFieldPassword);
    layout.addWidget(&signInButton);
    layout.addWidget(&registerButton);
    signInButton.setText("Sign in");
    registerButton.setText("Register");
    QObject::connect(&signInButton, &QPushButton::clicked, this, [&]() {
        api->userAPI.signInUser(textFieldLogin.text(), textFieldPassword.text());
    });
    QObject::connect(&registerButton, &QPushButton::clicked, this, [&]() {
        coordinator->openRegister();
    });
    QObject::connect(&api->userAPI, &BackendlessUserAPI::signInUserSuccess, this, [&]() {
        QMessageBox msgBox;
        msgBox.setText("Correct credentials");
        msgBox.exec();
    });
    QObject::connect(&api->userAPI, &BackendlessUserAPI::signInUserErrorBackendless, this, [&]() {
        QMessageBox msgBox;
        msgBox.setText("Wrong credentials");
        msgBox.exec();
    });
    setLayout(&layout);
}

SignInScreen::~SignInScreen() {

}
