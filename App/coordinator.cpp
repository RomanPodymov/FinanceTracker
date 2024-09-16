#include "coordinator.hpp"

void Coordinator::openSignIn() {
    registerScreen.hide();
    signInScreen.show();
}

void Coordinator::openRegister() {
    signInScreen.hide();
    registerScreen.show();
}
