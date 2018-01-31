#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include "ibasemodel.h"

class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(QObject *parent = nullptr);
    explicit Command(const Command& com);
    void setModel(IBaseModel* model);
    virtual ~Command();
    Command& operator =(const Command& com)
    {
        model = com.model;
        copy_model = com.copy_model;
        m_isMoved = com.m_isMoved;
        return *this;
    }
    virtual void Execute();
    virtual void unExecute();
    bool isMoved()const;
protected:
    IBaseModel *model;
    //Копия модели, чтобы сохранить предыдущее состояние
    IBaseModel *copy_model;
    bool m_isMoved;
    enum Comm
    {
        c_Up = 0,
        c_Down,
        c_Right,
        c_Left
    };
    int possibleMove(const Bar& bar, Comm c);
    bool hasBar(int x, int y);
private:
    bool modelIsChange;

signals:

public slots:
};

class CommandUp : public Command
{
    Q_OBJECT
public:
    explicit CommandUp(QObject *parent = nullptr);
    virtual ~CommandUp(){}
signals:

public slots:

    // Command interface
public:
    void Execute();
};

class CommandDown : public Command
{
    Q_OBJECT
public:
    explicit CommandDown(QObject *parent = nullptr);
    virtual ~CommandDown(){}
signals:

public slots:

    // Command interface
public:
    void Execute();
};

class CommandRight : public Command
{
    Q_OBJECT
public:
    explicit CommandRight(QObject *parent = nullptr);
    virtual ~CommandRight(){}
signals:

public slots:

    // Command interface
public:
    void Execute();
};

class CommandLeft : public Command
{
    Q_OBJECT
public:
    explicit CommandLeft(QObject *parent = nullptr);
    virtual ~CommandLeft(){}
signals:

public slots:

    // Command interface
public:
    void Execute();
};

#endif // COMMAND_H
