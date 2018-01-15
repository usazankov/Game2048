#ifndef IBASEMODEL_H
#define IBASEMODEL_H
#include <QObject>
#include "bar.h"

class IBarIterator
{

public:
    virtual Bar* next() = 0;
    virtual bool hasNext() = 0;
    virtual int size() = 0;
    virtual bool remove(int i) = 0;
    virtual Bar* element(int i) = 0;
    virtual bool addBar(const Bar& bar) = 0;
    virtual ~IBarIterator(){}
};
typedef IBarIterator* iterBar;
class IBaseModel : public QObject
{
    Q_OBJECT
public:
    explicit IBaseModel(QObject *parent = nullptr);

    //Размеры поля
    Q_INVOKABLE virtual int getLengthX()const = 0;
    Q_INVOKABLE virtual int getLengthY()const = 0;

    //Получить итератор
    Q_INVOKABLE virtual IBarIterator* createIterator() = 0;

    virtual ~IBaseModel();
signals:
    void modelChanged();
public slots:
};
#endif // IBASEMODEL_H
