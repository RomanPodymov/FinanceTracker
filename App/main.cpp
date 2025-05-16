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
#include <QFuture>

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
AnyNetworkAccessManager* networkManager;

void reloadScreen() {
    auto onLogoutSuccess = [](){
        reloadScreen();
    };
    QtFuture::connect(&api->userAPI, &BackendlessUserAPI::logoutSuccess)
        .then(onLogoutSuccess);
    
    auto user = api->userAPI.user();
    if (!user || user->userToken.isEmpty()) {
        coordinator->openSignIn();
    } else {
        coordinator->openAccounts();
    }
}

int main(int argc, char *argv[]) {
    QApplication myApp(argc, argv);

    networkManager = new StandardNetworkManager();
    api = new BackendlessAPI(
        networkManager,
        QSharedPointer<BackendlessSignInUserCoder>(new CustomSignInCoder()),
        readLocalConfigurationJSON()["APP_ID"].toString(),
        readLocalConfigurationJSON()["REST_API_KEY"].toString()
    );

    coordinator = new Coordinator();

    reloadScreen();
    
    return myApp.exec();
}
