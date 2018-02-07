#ifndef IBASEMODEL_H
#define IBASEMODEL_H
#include <QObject>
#include "bar.h"
#include <QDebug>
#include <QSettings>

class IBarIterator: public QObject
{
    Q_OBJECT
public:
    explicit IBarIterator(QObject *parent = nullptr);
    Q_INVOKABLE virtual Bar* next() = 0;
    Q_INVOKABLE virtual bool hasNext() = 0;
    Q_INVOKABLE virtual int size() = 0;
    Q_INVOKABLE virtual Bar* element(int i) = 0;
    Q_INVOKABLE virtual Bar* element(int x, int y) = 0;

    virtual ~IBarIterator(){
        //qDebug() << "Iter deleted";
    }
};

typedef IBarIterator* iterBar;
class IBaseModel : public QObject
{
    Q_OBJECT
public:
    enum State{
        WaitCommand,
        GameOver,
        Win
    };
    Q_ENUM(State)

    explicit IBaseModel(QObject *parent = nullptr);
    explicit IBaseModel(const IBaseModel& model);

    //Размеры поля
    Q_INVOKABLE virtual int getLengthX()const = 0;
    Q_INVOKABLE virtual int getLengthY()const = 0;

    //Получить итератор
    Q_INVOKABLE virtual IBarIterator* createIterator() = 0;

    //Функции удаления и добавления элемента
    Q_INVOKABLE virtual bool remove(int i) = 0;
    virtual bool addBar(const Bar& bar) = 0;
    virtual void clear() = 0;

    //Копирование и установка модели
    virtual IBaseModel* copyModel() = 0; //Необходимо освободить память самостоятельно
    virtual void setModel(IBaseModel* model) = 0;

    //Получить или установить текущее состояние модели
    Q_INVOKABLE virtual State state();
    virtual void setState(State state);

    //Функции сохранения и открытия модели
    Q_INVOKABLE virtual bool saveModel() = 0;
    virtual bool openModel() = 0;

    //Функции работы с очками
    Q_INVOKABLE virtual int score()const;
    virtual void setScore(int score);
    Q_INVOKABLE virtual int bestScore()const;
    virtual void setBestScore(int score);

    virtual ~IBaseModel();
signals:
    void modelChanged();
protected:
    int m_score;
    int m_bestScore;
    State currentState;
public slots:
};
#endif // IBASEMODEL_H
