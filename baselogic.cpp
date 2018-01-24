#include "baselogic.h"

BaseLogic::BaseLogic(IBaseModel *model) : QObject(model)
{
    this->model = model;
    //for(int i=0; i<1000; i++)
    //   addRandomBar();
    Bar temp;
    temp.setix(0);
    temp.setiy(1);
    temp.setnumeric(2);
    Bar temp2;
    temp2.setix(0);
    temp2.setiy(3);
    model->addBar(temp);
    model->addBar(temp2);
    barsMoved = 1;
}

void BaseLogic::up()
{
    Command *com = new CommandUp(this);
    com->setModel(model);
    com->Execute();
    commands.push_back(com);
}

void BaseLogic::down()
{
    Command *com = new CommandDown(this);
    com->setModel(model);
    com->Execute();
    commands.push_back(com);
}

void BaseLogic::right()
{
    Command *com = new CommandRight(this);
    com->setModel(model);
    com->Execute();
    commands.push_back(com);
}

void BaseLogic::left()
{
    Command *com = new CommandLeft(this);
    com->setModel(model);
    com->Execute();
    commands.push_back(com);
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
    iter->deleteLater();
}

bool BaseLogic::hasBar(int x, int y)
{
    iterBar iter = model->createIterator();
    Bar *temp = iter->element(x, y);
    iter->deleteLater();
    if(temp != nullptr)
    {
        return 1;
    }
    return 0;
}

void BaseLogic::process()
{
    if(commands.size() > 0){
        Command *com = commands.back();
        com->setModel(model);
        com->unExecute();
        commands.pop_back();
        delete com;
    }


    /*Bar temp;
    temp.setix(0);
    temp.setiy(4);
    Bar temp2;
    temp2.setix(1);
    temp2.setiy(4);
    model->addBar(temp);
    model->addBar(temp2);*/
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
    iter->deleteLater();
}
