#include <QMessageBox>
#include "signinscreen.hpp"

SignInScreen::SignInScreen(QWidget *parent): QWidget(parent),
    api(BackendlessAPI("", "")),
    textFieldLogin(this), textFieldPassword(this), signInButton(this) {
    layout.addWidget(&textFieldLogin);
    layout.addWidget(&textFieldPassword);
    layout.addWidget(&signInButton);
    signInButton.setText("Sign in");
    QObject::connect(&signInButton, &QPushButton::clicked, this, [&]() {
        api.userAPI.signInUser(textFieldLogin.text(), textFieldPassword.text());
    });
    QObject::connect(&api.userAPI, &BackendlessUserAPI::signInUserSuccess, this, [&]() {

    });
    QObject::connect(&api.userAPI, &BackendlessUserAPI::signInUserErrorBackendless, this, [&]() {
        QMessageBox msgBox;
        msgBox.setText("Wrong credentials");
        msgBox.exec();
    });
    setLayout(&layout);
}

SignInScreen::~SignInScreen() {

}
