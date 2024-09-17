//
//  coordinator.cpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#include <QMessageBox>
#include "coordinator.hpp"

void Coordinator::openError(QString text) {
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}

void Coordinator::openSignIn() {
    accountsScreen.hide();
    registerScreen.hide();
    signInScreen.show();
}

void Coordinator::openRegister() {
    accountsScreen.hide();
    signInScreen.hide();
    registerScreen.show();
}

void Coordinator::openAccounts() {
    signInScreen.hide();
    registerScreen.hide();
    accountsScreen.show();
}
