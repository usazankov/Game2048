#include "basemodel.h"

BaseModel::BaseModel(int x, int y, QObject *parent) : IBaseModel(parent), m_sizex(x), m_sizey(y)
{
    index = 0;
}

int BaseModel::index = 0;

BaseModel::BaseModel(const BaseModel &model)
{
    m_sizex = model.m_sizex;
    m_sizey = model.m_sizey;
    bars = model.bars;
}

BaseModel::~BaseModel()
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
    MapBarIterator * iter = new MapBarIterator(&bars, this);
    connect(this,SIGNAL(modelChanged()),iter,SLOT(onModelChanged()));
    return iter;
}

bool BaseModel::addBar(const Bar &bar)
{
    bars[index] = bar;
    bars[index].setidentificator(index);
    bars[index].setParent(this);//Иначе сборщик мусора qml удалит элемент bar
    ++index;
    emit modelChanged();
    return 1;

}

IBaseModel *BaseModel::copyModel()
{
    IBaseModel * model = new BaseModel(*this);
    return model;
}

void BaseModel::setModel(IBaseModel *model)
{
    if(model){
        iterBar iter = model->createIterator();
        Bar *bar = nullptr;
        while(iter->hasNext())
        {
            bar = iter->next();
            if(bar)
            {
                bars[bar->identificator()] = *bar;
            }
        }
        iter->deleteLater();
        emit modelChanged();
    }
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
