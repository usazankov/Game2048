#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QObject>
#include <QMap>
#include "ibasemodel.h"
#include "mapbariterator.h"


class BaseModel : public IBaseModel
{
    Q_OBJECT
public:
    explicit BaseModel(int x, int y, QObject *parent = nullptr);
private:

    int m_sizex;
    int m_sizey;
    QMap<p_point, Bar> bars;
    static int index;
signals:

    // IBaseModel interface
public:
    int getLengthX() const;
    int getLengthY() const;
    IBarIterator *createIterator();
    bool remove(int i);
    bool addBar(const Bar &bar);
};

#endif // BASEMODEL_H
