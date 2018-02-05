#ifndef BASELOGIC_H
#define BASELOGIC_H

#include <QObject>
#include "ibasemodel.h"
#include "basemodel.h"
#include <QDebug>
#include <cstdlib>
#include <QTime>
#include "command.h"
#include <QVector>
#include <QSettings>

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
    Q_INVOKABLE void revert();
    Q_INVOKABLE void newGame();
    Q_INVOKABLE void saveBestScore(int score);
    virtual ~BaseLogic();
private:
    void test();
    void addRandomBar();
    bool hasBar(int x, int y);
    void execute(Command * command);
    IBaseModel *model;
    bool barsMoved;
    QVector<Command*> commands;
    QSettings *settings;
    const QString keyScore = "Scores/bestScore";
signals:

public slots:
};

#endif // BASELOGIC_H
