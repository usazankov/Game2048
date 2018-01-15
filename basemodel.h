#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QObject>
#include <QMap>
#include "ibasemodel.h"

class BaseModel : public IBaseModel
{
    Q_OBJECT
public:
    explicit BaseModel(int x, int y, QObject *parent = nullptr);
private:
    int m_sizex;
    int m_sizey;
    QMap<int, Bar> bars;
    QMap<int, Bar>::iterator iter;
signals:

public slots:

    // IBaseModel interface
public:
    int getLengthX() const;
    int getLengthY() const;
    Bar *getElement(int i);
    Bar *next();
    int size();
    bool addBar(Bar &bar);
    bool delBar(int i);
};

#endif // BASEMODEL_H
