#include "command.h"

Command::Command(QObject *parent) : QObject(parent)
{
    modelIsChange = 0;
}

Command::Command(const Command &com)
{
    model = com.model;
    copy_model = com.copy_model;
}

void Command::setModel(IBaseModel *model)
{
    this->model = model;
}

Command::~Command()
{
    copy_model->deleteLater();
}

void Command::Execute()
{
    copy_model = model->copyModel();
    copy_model->setParent(this);
    iterBar iter = copy_model->createIterator();
    Bar * bar = nullptr;
    while(iter->hasNext())
    {
        bar = iter->next();
        if(bar)
        {
            bar->setParent(copy_model);
        }
    }
    iter->deleteLater();
}

void Command::unExecute()
{
    model->setModel(copy_model);
}

int Command::possibleMove(const Bar &bar, Comm c)
{
    int res = -1;
    switch (c)
    {
    case c_Up:
        // Если сверху нет края
        if( bar.iy() != 0 )
        {
            bool found = 0;
            iterBar iter = model->createIterator();
            for(int i = bar.iy() - 1; i >= 0; --i)
            {
                if(hasBar(bar.ix(),i))
                {
                    if(iter->element(bar.ix(),i)->numeric() != bar.numeric())
                    {
                        res = i + 1;
                        found = 1;
                    }else
                    {
                        qDebug() << "iden del:" << iter->element(bar.ix(),i)->identificator();
                        qDebug() << "num del:" << iter->element(bar.ix(),i)->numeric();
                        iter->element(bar.ix(),i)->setisDeleted(true);
                        iter->element(bar.identificator())->setnumeric(bar.numeric() * 2 );
                        qDebug() << "iden comp:" << bar.identificator();
                        qDebug() << "num comp:" << bar.numeric();
                        res = i;
                        found = 1;
                    }

                    break;
                }
            }
            iter->deleteLater();
            if(!found)
                res = 0;
        }
        break;
    case c_Down:
        // Если снизу нет края
        if( bar.iy() != model->getLengthX() - 1 )
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
        // Если справа нет края
        if( bar.ix() != model->getLengthX() - 1 )
        {
            bool found = 0;
            for(int i = bar.ix() + 1; i <  model->getLengthX(); ++i)
            {
                if(hasBar(i,bar.iy()))
                {
                    res = i - 1;
                    found = 1;
                    break;
                }
            }
            if(!found)
                res = model->getLengthX() - 1;
        }
        break;
    case c_Left:
        // Если слева нет края
        if( bar.ix() != 0 )
        {
            bool found = 0;
            for(int i = bar.ix() - 1; i >= 0; --i)
            {
                if(hasBar(i,bar.iy()))
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
    default:
        break;
    }
    return res;
}

bool Command::hasBar(int x, int y)
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

CommandUp::CommandUp(QObject *parent):Command(parent)
{

}

void CommandUp::Execute()
{
    if(model){
        Command::Execute();
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
        iter->deleteLater();
    }
}

CommandDown::CommandDown(QObject *parent):Command(parent)
{

}

void CommandDown::Execute()
{
    if(model){
        Command::Execute();
        iterBar iter = model->createIterator();
        Bar * bar = nullptr;
        //Двигаемся по столбцам:
        for(int i = 0; i < model->getLengthX(); ++i)
        {
            for(int j = model->getLengthY(); j >= 0; --j)
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
        iter->deleteLater();
    }
}

CommandRight::CommandRight(QObject *parent):Command(parent)
{

}

void CommandRight::Execute()
{
    if(model){
        Command::Execute();
        iterBar iter = model->createIterator();
        Bar * bar = nullptr;
        //Двигаемся по строкам:
        for(int j = 0; j < model->getLengthY(); ++j)
        {
            for(int i = model->getLengthX(); i >= 0; --i)
            {
                bar = iter->element(i,j);
                if(bar)
                {
                    int posmove = possibleMove(*bar, c_Right);
                    if( posmove >= 0)
                    {
                        bar->setix(posmove);
                    }
                }

            }
        }
        iter->deleteLater();
    }
}

CommandLeft::CommandLeft(QObject *parent):Command(parent)
{

}

void CommandLeft::Execute()
{
    if(model){
        Command::Execute();
        iterBar iter = model->createIterator();
        Bar * bar = nullptr;
        //Двигаемся по строкам:
        for(int j = 0; j < model->getLengthY(); ++j)
        {
            for(int i = 0; i < model->getLengthX(); ++i)
            {
                bar = iter->element(i,j);
                if(bar)
                {
                    int posmove = possibleMove(*bar, c_Left);
                    if( posmove >= 0)
                    {
                        bar->setix(posmove);
                    }
                }
            }
        }
        iter->deleteLater();
    }
}
