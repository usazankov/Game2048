#ifndef BASELOGIC_H
#define BASELOGIC_H

#include <QObject>
#include "ibasemodel.h"
#include "basemodel.h"
#include <random>
#include <QDebug>

class BaseLogic : public QObject
{
    Q_OBJECT
public:
    explicit BaseLogic(IBaseModel* model);
    Q_INVOKABLE void Up();
    Q_INVOKABLE void Down();
    Q_INVOKABLE void Right();
    Q_INVOKABLE void Left();
    void process();
private:

    void addRandomBar();
    bool hasBar(int x, int y);
    IBaseModel *model;
signals:

public slots:
};

#endif // BASELOGIC_H
