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

IBarIterator *BaseModel::createIterator()
{
    return new MapBarIterator(&bars, this);
}

