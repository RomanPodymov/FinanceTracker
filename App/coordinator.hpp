//
//  coordinator.hpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "signinscreen.hpp"
#include "registerscreen.hpp"
#include "accountsscreen.hpp"

class Coordinator {
public:
    void openError(QString);
    void openSignIn();
    void openRegister();
    void openAccounts();

private:
    SignInScreen signInScreen;
    RegisterScreen registerScreen;
    AccountsScreen accountsScreen;
};

#endif
