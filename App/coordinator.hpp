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

class Coordinator {
public:
    void openSignIn();
    void openRegister();

private:
    SignInScreen signInScreen;
    RegisterScreen registerScreen;
};

#endif
