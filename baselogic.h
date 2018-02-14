#ifndef BASELOGIC_H
#define BASELOGIC_H

#include <QObject>
#include "ibasemodel.h"
#include "basemodel.h"
#include <QDebug>
#include <cstdlib>
#include <deque>
#include <QTime>
#include "command.h"
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
    void checkModel();
    IBaseModel *model;
    bool barsMoved;
    std::deque<Command*> commands;
    QSettings *settings;
    const QString keyScore = "Scores/bestScore";
    const unsigned int sizeCommandHistory = 3;
signals:

public slots:
};

#endif // BASELOGIC_H
