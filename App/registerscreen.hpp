#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessAPI.hpp"

extern BackendlessAPI* api;

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
};

