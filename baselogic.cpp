#include "baselogic.h"

BaseLogic::BaseLogic(IBaseModel *model) : QObject(model)
{
    this->model = model;
    settings = new QSettings(this);
    for(int i=0; i<2; i++)
       addRandomBar();
    int score = settings->value(keyScore,0).toInt();
    model->setBestScore(score);
}

void BaseLogic::up()
{
    execute(new CommandUp(this));
}

void BaseLogic::down()
{
    execute(new CommandDown(this));
}

void BaseLogic::right()
{
    execute(new CommandRight(this));
}

void BaseLogic::left()
{
    execute(new CommandLeft(this));
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

void BaseLogic::execute(Command *command)
{
    command->setModel(model);
    command->Execute();
    commands.push_back(command);
}

void BaseLogic::process()
{
    if(commands.size() > 0)
    {
        Command *com = commands.back();
        if(com->isMoved())
        {
           addRandomBar();
           if(model->score() > model->bestScore())
           {
               model->setBestScore(model->score());
           }
        }
        else
        {
            commands.pop_back();
            delete com;
        }
    }
}

void BaseLogic::revert()
{
    if(commands.size() > 0){
        Command *com = commands.back();
        com->setModel(model);
        com->unExecute();
        commands.pop_back();
        delete com;
    }
}

void BaseLogic::saveBestScore(int score)
{
    if(model->bestScore() <= score)
    {
        settings->setValue(keyScore, score);
        model->setBestScore(score);
    }
}

BaseLogic::~BaseLogic()
{
    delete settings;
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
