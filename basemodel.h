#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QObject>
#include <QHash>
#include "ibasemodel.h"
#include "mapbariterator.h"
#include <QFile>

class BaseModel : public IBaseModel
{
    Q_OBJECT
public:
    explicit BaseModel(int x, int y, QObject *parent = nullptr);
    explicit BaseModel(const BaseModel& model);
    friend QDataStream& operator << (QDataStream &ds, const BaseModel &bm)
    {
        ds << bm.m_sizex;
        ds << bm.m_sizey;
        ds << bm.m_score;
        ds << bm.m_bestScore;
        ds << bm.index;
        ds << bm.bars.count();
        for(auto iter = bm.bars.cbegin(); iter != bm.bars.cend(); ++iter)
        {
            ds << iter.value();
        }
        return ds;
    }
    friend QDataStream& operator >>(QDataStream &ds, BaseModel &bm)
    {
        ds >> bm.m_sizex;
        ds >> bm.m_sizey;
        ds >> bm.m_score;
        ds >> bm.m_bestScore;
        ds >> bm.index;
        int count = 0;
        ds >> count;
        Bar bar;
        for(int i = 0; i < count; ++i)
        {
            ds >> bar;
            bm.bars[bar.identificator()] = bar;
        }
        return ds;
    }
    virtual ~BaseModel();
private:

    int m_sizex;
    int m_sizey;
    QHash<int, Bar> bars;
    int index;
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
    bool saveModel();
    bool openModel();
    void clear();
};

void saveBaseModel(const QString& file, const BaseModel& model);

#endif // BASEMODEL_H
