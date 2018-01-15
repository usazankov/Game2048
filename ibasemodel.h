#ifndef IBASEMODEL_H
#define IBASEMODEL_H
#include <QObject>
#include "bar.h"

class IBaseModel : public QObject
{
    Q_OBJECT
public:
    explicit IBaseModel(QObject *parent = nullptr);

    //Размеры поля
    Q_INVOKABLE virtual int getLengthX()const = 0;
    Q_INVOKABLE virtual int getLengthY()const = 0;

    //Добавить элемент с установкой идентификатора
    virtual bool addBar(Bar& bar) = 0;
    //Удалить элемент по идентификатору
    virtual bool delBar(int i) = 0;

    //Получить элемент по идентификатору
    Q_INVOKABLE virtual Bar* getElement(int i) = 0;

    //Получить следующий элемент
    Q_INVOKABLE virtual Bar* next() = 0;

    //Получить количество элементов
    Q_INVOKABLE virtual int size() = 0;

    virtual ~IBaseModel();
signals:

public slots:
};
#endif // IBASEMODEL_H
