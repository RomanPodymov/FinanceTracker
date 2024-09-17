//
//  signinscreen.hpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#ifndef SIGNIN_SCREEN_H
#define SIGNIN_SCREEN_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>

class SignInScreen: public QWidget {
    Q_OBJECT

public:
    SignInScreen(QWidget *parent = nullptr);
    ~SignInScreen();

private:
    QVBoxLayout layout;
    QLineEdit textFieldLogin;
    QLineEdit textFieldPassword;
    QPushButton signInButton;
    QPushButton registerButton;
};

#endif
