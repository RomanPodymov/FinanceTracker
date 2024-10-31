//
//  main.cpp
//  FinanceTracker
//
//  Created by Roman Podymov on 17/09/2024.
//  Copyright © 2024 FinanceTracker. All rights reserved.
//

#include "coordinator.hpp"
#include "BackendlessQt/StandardNetworkManager.hpp"
#include <QApplication>
#include <QFile>
#include <QJsonObject>

QJsonObject readLocalConfigurationJSON() {
    QFile localConfigurationFile(":/configurations/local.json");
    localConfigurationFile.open(QIODevice::ReadOnly);

    const auto& localConfigurationFileContent = QString::fromUtf8(localConfigurationFile.readAll()).simplified();
    const auto& localConfigurationFileJSON = QJsonDocument::fromJson(localConfigurationFileContent.toUtf8());
    localConfigurationFile.close();
    return localConfigurationFileJSON.object();
}

Coordinator* coordinator;
BackendlessAPI* api;
AnyNetworkAccessManager* networkManager = new StandardNetworkManager();

int main(int argc, char *argv[]) {
    QApplication myApp(argc, argv);

    api = new BackendlessAPI(
        networkManager,
        readLocalConfigurationJSON()["APP_ID"].toString(),
        readLocalConfigurationJSON()["REST_API_KEY"].toString()
    );

    coordinator = new Coordinator();
    if (api->userAPI.userToken().isEmpty()) {
        coordinator->openSignIn();
    } else {
        coordinator->openAccounts();
    }
    //coordinator->openAccounts();

    return myApp.exec();
}
