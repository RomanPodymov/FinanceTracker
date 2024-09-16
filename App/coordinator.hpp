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
