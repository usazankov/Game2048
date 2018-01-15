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
    QMap<int, Bar> bars;
signals:

public slots:

    // IBaseModel interface
public:
    int getLengthX() const;
    int getLengthY() const;
    IBarIterator *createIterator();
};

#endif // BASEMODEL_H
