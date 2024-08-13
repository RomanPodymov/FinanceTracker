#include "signinscreen.hpp"

SignInScreen::SignInScreen(QWidget *parent): QWidget(parent),
    api(BackendlessAPI("", "")) {

}

SignInScreen::~SignInScreen() {

}
