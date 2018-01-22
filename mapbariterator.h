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
    void onModelChanged();

public:

    // IBarIterator interface
    Bar *next();
    bool hasNext();
    int size();
    Bar *element(int i);
    Bar *element(int x, int y);

};

#endif // MAPBARITERATOR_H
