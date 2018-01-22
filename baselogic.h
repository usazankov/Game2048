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
    Q_INVOKABLE void Up();
    Q_INVOKABLE void Down();
    Q_INVOKABLE void Right();
    Q_INVOKABLE void Left();
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
