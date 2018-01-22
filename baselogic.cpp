#include "baselogic.h"

BaseLogic::BaseLogic(IBaseModel *model) : QObject(model)
{
    this->model = model;
}

void BaseLogic::up()
{
    iterBar iter = model->createIterator();
    Bar * bar = nullptr;
    //Двигаемся по столбцам:
    for(int i = 0; i < model->getLengthX(); ++i)
    {
        for(int j = 0; j < model->getLengthY(); ++j)
        {
            bar = iter->element(i,j);
            if(bar)
            {
                int posmove = possibleMove(*bar, c_Up);
                if( posmove >= 0)
                {
                    bar->setiy(posmove);
                }
            }

        }
    }
}

void BaseLogic::down()
{
    iterBar iter = model->createIterator();
    Bar * bar = nullptr;
    //Двигаемся по столбцам:
    for(int i = 0; i < model->getLengthX(); ++i)
    {
        for(int j = model->getLengthY() - 1; j >= 0; --j)
        {
            bar = iter->element(i,j);
            if(bar)
            {
                int posmove = possibleMove(*bar, c_Down);
                if( posmove >= 0)
                {
                    bar->setiy(posmove);
                }
            }

        }
    }
}

void BaseLogic::right()
{

}

void BaseLogic::left()
{

}

void BaseLogic::addRandomBar()
{
    iterBar iter = model->createIterator();
    if(iter->size() < model->getLengthX()*model->getLengthY())
    {
        Bar temp;
        srand(time(NULL));
        /*std::random_device random_device; // Источник энтропии.
        std::minstd_rand0 generator(random_device()); // Генератор случайных чисел.
        std::uniform_int_distribution<> distributionX(0, model->getLengthX() - 1);
        std::uniform_int_distribution<> distributionY(0, model->getLengthY() - 1);*/
        int x = rand() % model->getLengthX();
        int y = rand() % model->getLengthY();
        while(hasBar(x,y))
        {
            x = rand() % model->getLengthX();
            y = rand() % model->getLengthY();
        }
        temp.setix(x);
        temp.setiy(y);
        model->addBar(temp);
    }
    delete iter;
}

bool BaseLogic::hasBar(int x, int y)
{
    iterBar iter = model->createIterator();
    Bar *temp = iter->element(x, y);
    delete iter;
    if(temp != nullptr)
    {
        return 1;
    }
    return 0;
}

void BaseLogic::process()
{

    addRandomBar();

    /*Bar temp;
    temp.setix(0);
    temp.setiy(0);
    Bar temp2;
    temp2.setix(0);
    temp2.setiy(2);
    model->addBar(temp);
    model->addBar(temp2);*/
}

//Вычисляет расстояние до ближайшего бара, если будет двигаться в зависимости от команды
// 0 - движение невозможно
int BaseLogic::possibleMove(const Bar &bar, BaseLogic::Command c)
{
    int res = -1;
    switch (c)
    {
    case c_Up:
        // Если сверху нет края
        if( bar.iy() != 0 )
        {
            bool found = 0;
            for(int i = bar.iy() - 1; i >= 0; --i)
            {
                if(hasBar(bar.ix(),i))
                {
                    res = i + 1;
                    found = 1;
                    break;
                }
            }
            if(!found)
                res = 0;
        }
        break;
    case c_Down:
        // Если снизу нет края
        if( bar.iy() != model->getLengthY() - 1 )
        {
            bool found = 0;
            for(int i = bar.iy() + 1; i <  model->getLengthY(); ++i)
            {
                if(hasBar(bar.ix(),i))
                {
                    res = i - 1;
                    found = 1;
                    break;
                }
            }
            if(!found)
                res = model->getLengthY() - 1;
        }
        break;
    case c_Right:

        break;
    case c_Left:

        break;
    default:
        break;
    }
    return res;
}

void BaseLogic::test()
{
    iterBar iter = model->createIterator();
    Bar *temp = nullptr;
    while(iter->hasNext())
    {
        temp = iter->next();
        if(temp)
        {
            temp->setix(temp->ix() + 1);
            //break;
        }
    }
    delete iter;
}
