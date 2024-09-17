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
    registerScreen.hide();
    signInScreen.show();
}

void Coordinator::openRegister() {
    signInScreen.hide();
    registerScreen.show();
}
