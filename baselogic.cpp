#include "baselogic.h"

BaseLogic::BaseLogic(IBaseModel *model) : QObject(model)
{
    this->model = model;
}

void BaseLogic::Up()
{
    iterBar iter = model->createIterator();
    Bar * bar = nullptr;
    //Двигаемся по столбцам:
    for(int i = 1; i < model->getLengthX() - 1; ++i)
    {
        for(int j = 0; j < model->getLengthY() - 1; ++j)
        {
            bar = iter->element(i,j);
            if(bar)
            {
                int posmove = possibleMove(*bar, c_Up);
                if( posmove > 0)
                {
                    bar->setiy(bar->iy()- posmove);
                }
            }

        }
    }
}

void BaseLogic::Down()
{

}

void BaseLogic::Right()
{

}

void BaseLogic::Left()
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
    Up();
    addRandomBar();
}

//Вычисляет расстояние до ближайшего бара, если будет двигаться в зависимости от команды
// 0 - движение невозможно
int BaseLogic::possibleMove(const Bar &bar, BaseLogic::Command c)
{
    int res = 0;
    switch (c)
    {
    case c_Up:
        // Если сверху нет края
        if( bar.iy() != 0 )
        {
            bool found = 0;
            for(int i = bar.iy(); i <= 0; --i)
            {
                if(hasBar(bar.ix(),i))
                {
                    res = bar.iy() - i;
                    found = 1;
                    break;
                }
            }
            if(!found)
                res = bar.iy();
        }
        break;
    case c_Down:

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
