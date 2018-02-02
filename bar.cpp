#include "bar.h"

Bar::Bar(QObject *parent):QObject(parent), m_identificator(0), m_numeric(2), m_ix(0), m_iy(0), m_isDeleted(0)
{

}

Bar::Bar(const Bar &b)
{
    m_identificator = b.m_identificator;
    m_numeric = b.m_numeric;
    m_ix = b.m_ix;
    m_iy = b.m_iy;
    m_isDeleted = b.m_isDeleted;
}

void Bar::setnumeric(int numeric)
{
    if (m_numeric == numeric)
        return;

    m_numeric = numeric;
    emit numericChanged(m_numeric);
}

int Bar::numeric() const
{
    return m_numeric;
}

int Bar::identificator() const
{
    return m_identificator;
}

void Bar::setidentificator(int identificator)
{
    if (m_identificator == identificator)
        return;

    m_identificator = identificator;
    emit identificatorChanged(m_identificator);
}

void Bar::setix(int ix)
{
    if (m_ix == ix)
        return;

    m_ix = ix;
    emit ixChanged(m_ix);
}

int Bar::ix() const
{
    return m_ix;
}

void Bar::setiy(int iy)
{
    if (m_iy == iy)
        return;

    m_iy = iy;
    emit iyChanged(m_iy);
}

int Bar::iy() const
{
    return m_iy;
}

bool Bar::isDeleted() const
{
    return m_isDeleted;
}

void Bar::setisDeleted(bool isDeleted)
{
    m_isDeleted = isDeleted;
    emit isDeletedChanged(m_isDeleted);
}
