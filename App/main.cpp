#include "signinscreen.hpp"
#include "registerscreen.hpp"
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

BackendlessAPI* api;
SignInScreen* signInScreen;
RegisterScreen* registerScreen;

int main(int argc, char *argv[])
{
    QApplication myApp(argc, argv);

    api = new BackendlessAPI(readLocalConfigurationJSON()["APP_ID"].toString(), readLocalConfigurationJSON()["REST_API_KEY"].toString());
    signInScreen = new SignInScreen();
    registerScreen = new RegisterScreen();

    signInScreen->show();

    return myApp.exec();
}
