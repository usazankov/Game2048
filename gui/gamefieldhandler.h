#ifndef GAMEFIELDHANDLER_H
#define GAMEFIELDHANDLER_H

#include <QObject>
#include "ibasemodel.h"

class GameFieldHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(IBaseModel* model READ model WRITE setModel NOTIFY modelChanged)

public:
    explicit GameFieldHandler(QObject *parent = nullptr);

    IBaseModel* model() const;
private:
    IBaseModel* m_model;
signals:
    void modelChanged(IBaseModel* model);

public slots:
    void setModel(IBaseModel* model);
};

#endif // GAMEFIELDHANDLER_H
