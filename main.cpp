#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "bar.h"
#include "tests/testbasemodel.h"
#include "baselogic.h"
#include "gui/gamefieldhandler.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    IBaseModel *model = new BaseModel(100,100);
    BaseLogic logic(model);
    GameFieldHandler gameField;
    gameField.setModel(model);
    QQmlContext *pcon=engine.rootContext();
    pcon->setContextProperty("logic", &logic);
    pcon->setContextProperty("gameField", &gameField);
    pcon->setContextProperty("model", model);
    qmlRegisterType<Bar>("io.qt.Game2048", 1, 0, "Bar");
    qmlRegisterInterface<IBarIterator>("IBarIterator");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
