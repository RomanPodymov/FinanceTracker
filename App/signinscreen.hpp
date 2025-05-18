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
#include <BackendlessQt/BackendlessAPI.hpp>

struct CustomSignInUser: BackendlessSignInUser {
    QString someCustomField;

    CustomSignInUser(
        QJsonObject jsonObject
    ): BackendlessSignInUser(jsonObject), someCustomField(jsonObject["someCustomField"].toString()) {

    }

    CustomSignInUser(): BackendlessSignInUser() { }
};

class CustomSignInCoder: public BackendlessSignInUserCoder {
    Codable* decode(QJsonObject obj) override {
        return new CustomSignInUser(obj);
    }

    void write(QTextStream& stream, QSharedPointer<Codable> codable, QSharedPointer<Codable> defaultValue) override {
        auto userValue = (CustomSignInUser*)(defaultValue.get() ? defaultValue.get() : codable.get());
        stream << userValue->userToken << Qt::endl;
        stream << userValue->email << Qt::endl;
        stream << userValue->name << Qt::endl;
        stream << userValue->someCustomField << Qt::endl;
    }

    Codable* read(QTextStream& stream) override {
        auto result = new CustomSignInUser();
        stream >> result->userToken >> Qt::endl;
        stream >> result->email >> Qt::endl;
        stream >> result->name >> Qt::endl;
        stream >> result->someCustomField >> Qt::endl;
        return result;
    }
};

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
