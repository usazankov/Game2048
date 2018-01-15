#include "testbasemodel.h"

TestBaseModel::TestBaseModel(QObject *parent) : QObject(parent)
{
    IBaseModel * i = new BaseModel(4, 4, this);
    iterBar iter = i->createIterator();

    delete iter;
}
