#ifndef BASELOGIC_H
#define BASELOGIC_H

#include <QObject>
#include "ibasemodel.h"
#include "basemodel.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

class BaseLogic : public QObject
{
    Q_OBJECT
public:
    explicit BaseLogic(IBaseModel* model);
    Q_INVOKABLE void up();
    Q_INVOKABLE void down();
    Q_INVOKABLE void right();
    Q_INVOKABLE void left();
    Q_INVOKABLE void process();
private:
    enum Command
    {
        c_Up = 0,
        c_Down,
        c_Right,
        c_Left
    };
    int possibleMove(const Bar& bar, Command c);
    void test();
    void addRandomBar();
    bool hasBar(int x, int y);
    IBaseModel *model;
signals:

public slots:
};

#endif // BASELOGIC_H
