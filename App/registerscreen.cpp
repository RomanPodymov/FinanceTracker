#include <QMessageBox>
#include "registerscreen.hpp"

RegisterScreen::RegisterScreen(QWidget *parent): QWidget(parent),
    textFieldLogin(this), textFieldPassword(this), registerButton(this) {
    layout.addWidget(&textFieldLogin);
    layout.addWidget(&textFieldPassword);
    layout.addWidget(&registerButton);
    registerButton.setText("Register");
    QObject::connect(&registerButton, &QPushButton::clicked, this, [&]() {
        BackendlessRegisterUserRepresentable* user = new BackendlessRegisterUser(textFieldLogin.text(), textFieldPassword.text(), "name");
        api->userAPI.registerUser(*user);
    });
    /*QObject::connect(&api->userAPI, &BackendlessUserAPI::signInUserSuccess, this, [&]() {

    });
    QObject::connect(&api->userAPI, &BackendlessUserAPI::signInUserErrorBackendless, this, [&]() {
        QMessageBox msgBox;
        msgBox.setText("Wrong credentials");
        msgBox.exec();
    });*/
    setLayout(&layout);
}

RegisterScreen::~RegisterScreen() {

}
