#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "bar.h"
#include "tests/testbasemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    TestBaseModel tb;
    return app.exec();
}
