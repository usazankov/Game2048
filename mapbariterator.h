#ifndef MAPBARITERATOR_H
#define MAPBARITERATOR_H

#include <QObject>
#include "ibasemodel.h"
#include <QMap>

class MapBarIterator : public IBarIterator
{
    Q_OBJECT
    typedef QMap<int, Bar> MapBars;
public:
    explicit MapBarIterator(MapBars *bars, QObject *parent = nullptr);
    ~MapBarIterator();
private:
    MapBars *bars;
    QMap<int, Bar>::iterator iter;
signals:

public slots:

    // IBarIterator interface
public:
    Bar *next();
    bool hasNext();
    int size();
    bool remove(int i);
    Bar *element(int i);
    bool addBar(const Bar &bar);
    int maxSize();
};

#endif // MAPBARITERATOR_H
