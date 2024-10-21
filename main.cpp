#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

#include "ui/gitusermodel.h"
#include "ui/uimanager.h"

using namespace jjfp;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    auto ui = ui::UIManager{};

    // Register types
    //qmlRegisterType<ui::GitUserModel>("com.jjfp", 1, 0, "GitUserModel");

    qmlRegisterSingletonInstance<ui::UIManager>("com.jjfp", 1, 0, "UIManager", &ui);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("AdvancedUI", "Main");

    return app.exec();
}
