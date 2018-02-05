#include "ibasemodel.h"

IBaseModel::IBaseModel(QObject *parent):QObject(parent)
{
    m_score = 0;

}

IBaseModel::IBaseModel(const IBaseModel &model)
{
    m_score = model.m_score;
}

void IBaseModel::setScore(int score)
{
    m_score = score;
}

int IBaseModel::bestScore() const
{
    return m_bestScore;
}

void IBaseModel::setBestScore(int score)
{
    m_bestScore = score;
}

int IBaseModel::score()const
{
    return m_score;
}

IBaseModel::~IBaseModel()
{

}

IBarIterator::IBarIterator(QObject *parent):QObject(parent)
{

}
