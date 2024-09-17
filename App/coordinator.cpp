//
//  coordinator.cpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#include "coordinator.hpp"

void Coordinator::openSignIn() {
    registerScreen.hide();
    signInScreen.show();
}

void Coordinator::openRegister() {
    signInScreen.hide();
    registerScreen.show();
}
