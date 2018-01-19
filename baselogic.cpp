#include "baselogic.h"

BaseLogic::BaseLogic(IBaseModel *model) : QObject(model)
{
    this->model = model;
}

void BaseLogic::Up()
{

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
        std::random_device random_device; // Источник энтропии.
        std::minstd_rand0 generator(random_device()); // Генератор случайных чисел.
        std::uniform_int_distribution<> distributionX(0, model->getLengthX() - 1);
        std::uniform_int_distribution<> distributionY(0, model->getLengthY() - 1);
        int x = distributionX(generator);
        int y = distributionY(generator);
        int count = 0;
        while(hasBar(x,y))
        {
            x = distributionX(generator);
            y = distributionY(generator);
            ++count;
        }
        qDebug() << "count="<<count;
        temp.setix(x);
        temp.setiy(y);
        model->addBar(temp);
    }
    delete iter;
}

bool BaseLogic::hasBar(int x, int y)
{
    iterBar iter = model->createIterator();
    Bar *temp = nullptr;
    while(iter->hasNext())
    {
        temp = iter->next();
        if(temp)
        {
            if(temp->ix() == x && temp->iy() == y)
            {
                delete iter;
                return 1;
            }
        }
    }
    delete iter;
    return 0;
}

void BaseLogic::process()
{
    addRandomBar();
    /*while(iter->hasNext())
    {
        temp = iter->next();
        if(temp)
        {
            qDebug() << "ident: " << temp->identificator();
            qDebug() << "X: "<< temp->ix();
            qDebug() << "Y:" << temp->iy() << "\n";
        }
    }
    qDebug() << "size: " << iter->size();*/
}
