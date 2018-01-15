#include "mapbariterator.h"

MapBarIterator::MapBarIterator(MapBars *bars, QObject *parent) : QObject(parent)
{
    this->bars = bars;
    iter = bars->begin();
}

MapBarIterator::~MapBarIterator()
{

}

Bar *MapBarIterator::next()
{
    Bar *bar = nullptr;
    if( iter != bars->end() )
    {
        bar = &(*iter);
        iter++;
    }
    return bar;
}

bool MapBarIterator::hasNext()
{
    if(bars->size() > 0)
    {
        if(iter == bars->end())
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
        return bars->size();
    }
    return 0;
}

bool MapBarIterator::remove(int i)
{
    if(bars->contains(i))
    {
        bars->remove(i);
        iter = bars->begin();
    }
}

Bar *MapBarIterator::element(int i)
{
    if(bars->contains(i))
    {
        return &((*bars)[i]);
    }
}

bool MapBarIterator::addBar(const Bar &bar)
{
    int i = 0;
    int temp = 0;
    while(1)
    {
        if(!bars->contains(i))
        {
            temp = i;
            break;
        }
        ++i;
    }

    (*bars)[temp] = bar;
    ((*bars)[temp]).setidentificator(temp);
    iter = bars->begin();
    return 1;
}
