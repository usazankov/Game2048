#include "baselogic.h"

BaseLogic::BaseLogic(IBaseModel *model) : QObject(model)
{
    this->model = model;
    settings = new QSettings(this);
    if(!model->openModel())
    {
        newGame();
    }
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
        int seed = QTime::currentTime().msecsSinceStartOfDay();
        srand(seed);
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
    if(model->state() == IBaseModel::WaitCommand){
        command->setModel(model);
        command->Execute();
    }
    commands.push_back(command);
    if(commands.size() > sizeCommandHistory)
    {
        commands.pop_front();
    }
}

void BaseLogic::checkModel()
{
    bool res = 0;
    iterBar iter = model->createIterator();
    //Проверка на проигрыш
    if(iter->size() == model->getLengthX()*model->getLengthY())
    {
        Bar * bar = nullptr;
        //Двигаемся по столбцам:
        for(int i = 0; i < model->getLengthX(); ++i)
        {
            for(int j = 0; j < model->getLengthY(); ++j)
            {
                bar = iter->element(i,j);
                if(bar){
                    Bar *bari = iter->element(i+1,j);
                    if(bari){
                        if(bar->numeric() == bari->numeric())
                        {
                            res = 1;
                            break;
                        }
                    }
                    Bar *barj = iter->element(i,j+1);
                    if(barj){
                        if(bar->numeric() == barj->numeric())
                        {
                            res = 1;
                            break;
                        }
                    }
                }
            }
            if(res)break;
        }
        if(!res)
        {
            model->setState(IBaseModel::GameOver);
        }
        else
        {
            model->setState(IBaseModel::WaitCommand);
        }
    }
    else
    {
        model->setState(IBaseModel::WaitCommand);
    }

    //Проверка на выигрыш
    Bar * bar = nullptr;
    while(iter->hasNext())
    {
        bar = iter->next();
        if(bar)
        {
            if(bar->numeric() >= 2048)
            {
                model->setState(IBaseModel::Win);
            }
        }
    }

    delete iter;
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
    checkModel();
}

void BaseLogic::revert()
{
    if(model->state() != IBaseModel::Win){
        if(commands.size() > 0){
            Command *com = commands.back();
            com->setModel(model);
            com->unExecute();
            commands.pop_back();
            delete com;
            model->setState(IBaseModel::WaitCommand);
        }
    }
}

void BaseLogic::newGame()
{
    model->clear();
    commands.clear();
    model->setState(IBaseModel::WaitCommand);
    for(int i=0; i<2; i++)
        addRandomBar();
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
    model->saveModel();
    QFile file(game::nameFileToSaveState);
    if(file.open(QIODevice::Append))
    {
        QDataStream stream(&file);
        stream << *this;
    }
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
