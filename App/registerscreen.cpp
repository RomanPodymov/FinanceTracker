#include <QMessageBox>
#include "registerscreen.hpp"

RegisterScreen::RegisterScreen(BackendlessAPI* _api, QWidget *parent): QWidget(parent),
    api(api),
    textFieldLogin(this), textFieldPassword(this), registerButton(this) {
    layout.addWidget(&textFieldLogin);
    layout.addWidget(&textFieldPassword);
    layout.addWidget(&registerButton);
    registerButton.setText("Register");
    QObject::connect(&registerButton, &QPushButton::clicked, this, [&]() {
        api->userAPI.registerUser(BackendlessRegisterUser(textFieldLogin.text(), textFieldPassword.text(), ""));
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
