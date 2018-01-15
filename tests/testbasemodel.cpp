#include "testbasemodel.h"

TestBaseModel::TestBaseModel(QObject *parent) : QObject(parent)
{
    IBaseModel * i = new BaseModel(4, 4, this);
    int a = i->getLengthX();
    int b = i->getLengthY();
    Bar temp;
    Bar temp2;
    Bar temp3;
    temp3.setix(5);
    temp3.setiy(3);
    temp3.setnumeric(16);
    i->addBar(temp);
    i->addBar(temp2);
    i->addBar(temp3);
    int size = i->size();
    Bar *p_temp = 0;
    for(int a = 0; a < i->size() + 2; ++a)
    {
        p_temp = i->next();
        if(p_temp)
        {
            temp = *(p_temp);
        }
    }
}
