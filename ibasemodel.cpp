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

int IBaseModel::score()
{
    return m_score;
}

IBaseModel::~IBaseModel()
{

}

IBarIterator::IBarIterator(QObject *parent):QObject(parent)
{

}
