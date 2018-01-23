#ifndef BASELOGIC_H
#define BASELOGIC_H

#include <QObject>
#include "ibasemodel.h"
#include "basemodel.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include "command.h"
#include <QVector>

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
    void test();
    void addRandomBar();
    bool hasBar(int x, int y);
    IBaseModel *model;
    bool barsMoved;
    QVector<Command*> commands;
signals:

public slots:
};

#endif // BASELOGIC_H
