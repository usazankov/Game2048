#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "bar.h"
#include "baselogic.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("Game2048");
    QGuiApplication::setOrganizationName("YuriSazankov");
    QQmlApplicationEngine engine;

    BaseModel model(4,4);
    BaseLogic logic(&model);
    QQmlContext *pcon=engine.rootContext();
    pcon->setContextProperty("logic", &logic);
    pcon->setContextProperty("model", &model);
    qmlRegisterType<Bar>("io.qt.Game2048", 1, 0, "Bar");
    qmlRegisterInterface<IBarIterator>("IBarIterator");
    qmlRegisterUncreatableType<IBaseModel>("io.qt.Game2048", 1, 0,"IBaseModel","Error: only enums");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
