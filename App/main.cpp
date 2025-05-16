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

struct CustomSignInUser: BackendlessSignInUser {
    QString someCustomField;

    CustomSignInUser(
        QJsonObject jsonObject
    ): BackendlessSignInUser(jsonObject), someCustomField(jsonObject["someCustomField"].toString()) {

    }

    CustomSignInUser() { }
};

class CustomSignInCoder: public BackendlessSignInUserCoder {
    Codable* decode(QJsonObject obj) override {
        return new CustomSignInUser(obj);
    }

    void write(QTextStream& stream, QSharedPointer<Codable> codable, QSharedPointer<Codable> defaultValue) override {
        auto userValue = (CustomSignInUser*)(defaultValue.get() ? defaultValue.get() : codable.get());
        stream << userValue->userToken << Qt::endl;
        stream << userValue->email << Qt::endl;
        stream << userValue->name << Qt::endl;
        stream << userValue->someCustomField << Qt::endl;
    }

    Codable* read(QTextStream& stream) override {
        auto result = new CustomSignInUser();
        stream >> result->userToken >> Qt::endl;
        stream >> result->email >> Qt::endl;
        stream >> result->name >> Qt::endl;
        stream >> result->someCustomField >> Qt::endl;
        return result;
    }
};

int main(int argc, char *argv[]) {
    QApplication myApp(argc, argv);

    networkManager = new StandardNetworkManager();
    api = new BackendlessAPI(
        networkManager,
        QSharedPointer<BackendlessSignInUserCoder>(new BackendlessSignInUserCoder()),
        readLocalConfigurationJSON()["APP_ID"].toString(),
        readLocalConfigurationJSON()["REST_API_KEY"].toString()
    );

    coordinator = new Coordinator();

    reloadScreen();
    
    return myApp.exec();
}
