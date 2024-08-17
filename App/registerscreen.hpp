#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessAPI.hpp"

class RegisterScreen: public QWidget
{
    Q_OBJECT

public:
    RegisterScreen(BackendlessAPI&, QWidget *parent = nullptr);
    ~RegisterScreen();

private:
    BackendlessAPI& api;

private:
    QVBoxLayout layout;
    QLineEdit textFieldLogin;
    QLineEdit textFieldPassword;
    QPushButton registerButton;
};

