#include "mapbariterator.h"

MapBarIterator::MapBarIterator(MapBars *bars, QObject *parent) : IBarIterator(parent)
{
    this->bars = bars;
    iter = bars->begin();
}

MapBarIterator::~MapBarIterator()
{

}

void MapBarIterator::onModelChanged()
{
    iter = bars->begin();
}

Bar *MapBarIterator::next()
{
    Bar *bar = nullptr;
    if( iter != bars->end() )
    {
        bar = &(iter.value());
        iter++;
    }
    return bar;
}

bool MapBarIterator::hasNext()
{
    if(bars->size() > 0)
    {
        if(iter == bars->end() )
            return 0;
        else
            return 1;
    }else
        return 0;
}

int MapBarIterator::size()
{
    if(bars)
    {
        int counts = 0;
        for(auto iter = bars->cbegin(); iter != bars->cend(); ++iter)
        {
            if(iter.value().isDeleted())
                ++counts;
        }
        return bars->size() - counts;
    }
    return 0;
}

Bar *MapBarIterator::element(int i)
{
    if(bars->contains(i))
    {
        return &((*bars)[i]);
    }
    return nullptr;
}

Bar *MapBarIterator::element(int x, int y)
{
    Bar *bar = nullptr;
    if(bars->size() > 0)
    {
        for(auto iter = bars->begin(); iter != bars->end(); ++iter)
        {
            if(iter.value().ix() == x && iter.value().iy() == y && iter.value().isDeleted() == 0)
            {
                bar = &iter.value();
                break;
            }
        }
    }
    return bar;
}


