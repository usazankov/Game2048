#include "gamefieldhandler.h"

GameFieldHandler::GameFieldHandler(QObject *parent) : QObject(parent)
{

}

IBaseModel* GameFieldHandler::model() const
{
    return m_model;
}

void GameFieldHandler::setModel(IBaseModel* model)
{
    if (m_model == model)
        return;

    m_model = model;
    emit modelChanged(m_model);
}
