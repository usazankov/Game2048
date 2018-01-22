#include "basemodel.h"

BaseModel::BaseModel(int x, int y, QObject *parent) : IBaseModel(parent), m_sizex(x), m_sizey(y)
{

}

int BaseModel::index = 0;

int BaseModel::getLengthX() const
{
    return m_sizex;
}

int BaseModel::getLengthY() const
{
    return m_sizey;
}

IBarIterator *BaseModel::createIterator()
{
    MapBarIterator * iter = new MapBarIterator(&bars, this);
    connect(this,SIGNAL(modelChanged()),iter,SLOT(onModelChanged()));
    return iter;
}

bool BaseModel::addBar(const Bar &bar)
{
    p_point p;
    p.x = bar.ix();
    p.y = bar.iy();
    int i = 0;
    int temp = 0;
    if(!bars.contains(p))
    {
        bars[p] = bar;
        bars[p].setidentificator(index++);
        bars[p].setParent(this);//Иначе сборщик мусора qml удалит элемент bar
        emit modelChanged();
        return 1;
    }else
    {
        return 0;
    }

}

bool BaseModel::remove(int i)
{
    for(auto iter = bars.begin(); iter != bars.end(); ++iter)
    {
        if(iter.value().identificator() == i)
        {
            p_point t;
            t.x = iter.value().ix();
            t.y = iter.value().iy();
            bars.remove(t);
            return 1;
        }
    }
    return 0;
}
