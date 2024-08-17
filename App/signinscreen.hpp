#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessAPI.hpp"
#include "registerscreen.hpp"

class SignInScreen: public QWidget
{
    Q_OBJECT

public:
    SignInScreen(QWidget *parent = nullptr);
    ~SignInScreen();

private:
    QJsonObject readLocalConfigurationJSON();

private:
    BackendlessAPI api;

private:
    QVBoxLayout layout;
    QLineEdit textFieldLogin;
    QLineEdit textFieldPassword;
    QPushButton signInButton;
    QPushButton registerButton;

    RegisterScreen registerScreen;
};

