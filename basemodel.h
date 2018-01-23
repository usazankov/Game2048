#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QObject>
#include <QHash>
#include "ibasemodel.h"
#include "mapbariterator.h"


class BaseModel : public IBaseModel
{
    Q_OBJECT
public:
    explicit BaseModel(int x, int y, QObject *parent = nullptr);
    explicit BaseModel(const BaseModel& model);
    virtual ~BaseModel();
private:

    int m_sizex;
    int m_sizey;
    QHash<int, Bar> bars;
    static int index;
signals:

    // IBaseModel interface
public:
    int getLengthX() const;
    int getLengthY() const;
    IBarIterator *createIterator();
    bool remove(int i);
    bool addBar(const Bar &bar);
    IBaseModel *copyModel();
    void setModel(IBaseModel *model);
};

#endif // BASEMODEL_H
