#include "basemodel.h"

BaseModel::BaseModel(int x, int y, QObject *parent) : IBaseModel(parent), m_sizex(x), m_sizey(y)
{

}

int BaseModel::getLengthX() const
{
    return m_sizex;
}

int BaseModel::getLengthY() const
{
    return m_sizey;
}

bool BaseModel::addBar(Bar &bar)
{
    if(bars.size() < m_sizex * m_sizey)
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
        bar.setidentificator(temp);
        bars[temp] = bar;
        iter = bars.begin();
        return 1;
    }else
        return 0;
}

bool BaseModel::delBar(int i)
{
    if(bars.contains(i))
    {
        bars.remove(i);
        iter = bars.begin();
        return 1;
    }else
        return 0;
}

Bar *BaseModel::getElement(int i)
{
    return &bars[i];
}

int BaseModel::size()
{
    return bars.size();
}

Bar *BaseModel::next()
{
    Bar *bar = nullptr;
    if( iter != bars.end() )
    {
        bar = &(*iter);
        iter++;
    }
    else
    {
        iter = bars.begin();
    }
    return bar;
}
