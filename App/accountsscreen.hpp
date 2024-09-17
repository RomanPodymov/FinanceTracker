//
//  accountsscreen.hpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#ifndef ACCOUNTS_SCREEN_H
#define ACCOUNTS_SCREEN_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "BackendlessAPI.hpp"

extern BackendlessAPI* api;

class AccountsScreen: public QWidget
{
    Q_OBJECT

public:
    AccountsScreen(QWidget *parent = nullptr);
    ~AccountsScreen();

private:
    QVBoxLayout layout;
};

#endif
