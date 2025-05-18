//
//  accountsscreen.cpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#include <QMessageBox>
#include <QJsonArray>
#include <QJsonObject>
#include <QFuture>
#include "accountsscreen.hpp"
#include "coordinator.hpp"

extern Coordinator* coordinator;

AccountsScreen::AccountsScreen(QWidget *parent): QWidget(parent) {
    auto onLoadTableItemsSuccess = [&](QString replyValue) {
        qDebug() << "Loaded " << replyValue;

        QJsonParseError jsonError;
        auto jsonResponse = QJsonDocument::fromJson(replyValue.toUtf8(), &jsonError);

        switch (jsonError.error) {
        case QJsonParseError::NoError:
            break;
        default:
            return;
        }

        auto jsonObject = jsonResponse.array();
        for (const auto& item : jsonObject) {
            auto lessonObject = item.toObject();
            auto money = lessonObject["money"].toInt();

            QPushButton* button = new QPushButton(this);
            button->setText(QString::number(money));
            layout.addWidget(button);
        }
    };

    auto onGetCount = [&](int count) {
        api->loadTableItems("Accounts", 1, 0);
        return QtFuture::connect(api, &BackendlessAPI::loadTableItemsSuccess);
    };

    QtFuture::connect(api, &BackendlessAPI::getItemsCountSuccess)
        .then(onGetCount)
        .unwrap()
        .then(onLoadTableItemsSuccess);

    setLayout(&layout);
    api->getItemsCount("Accounts");

    QtFuture::connect(api, &BackendlessAPI::loadTableItemsSuccess)
        .then(onLoadTableItemsSuccess);

    api->loadTableItems("Accounts", 100, 0, "money = 1002 OR money = 1001");

    QPushButton* buttonLogout = new QPushButton(this);
    buttonLogout->setText("Logout");
    QObject::connect(buttonLogout, &QPushButton::clicked, this, [&]() {
        api->userAPI.logout();
    });
    layout.addWidget(buttonLogout);
}

AccountsScreen::~AccountsScreen() {

}
