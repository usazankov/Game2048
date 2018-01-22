#include "basemodel.h"

BaseModel::BaseModel(int x, int y, QObject *parent) : IBaseModel(parent), m_sizex(x), m_sizey(y)
{
    index = 0;
}

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
    int i = 0;
    int temp = 0;
    while(1)
    {
        if(!bars.contains(i))
        {
            temp = i;
            break;
        }
        ++i;
    }
    bars[temp] = bar;
    bars[temp].setidentificator(temp);
    bars[temp].setParent(this);//Иначе сборщик мусора qml удалит элемент bar

    emit modelChanged();
    return 1;

}

bool BaseModel::remove(int i)
{
    if(bars.contains(i))
    {
        bars.remove(i);
        emit modelChanged();
        return 1;
    }
    return 0;
}
