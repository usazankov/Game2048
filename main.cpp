#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "bar.h"
#include "tests/testbasemodel.h"
#include "baselogic.h"
#include "gui/gamefieldhandler.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("Game2048");
    QQmlApplicationEngine engine;
    BaseModel model(10,10);
    BaseLogic logic(&model);
    QQmlContext *pcon=engine.rootContext();
    pcon->setContextProperty("logic", &logic);
    pcon->setContextProperty("model", &model);
    qmlRegisterType<Bar>("io.qt.Game2048", 1, 0, "Bar");
    qmlRegisterInterface<IBarIterator>("IBarIterator");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
