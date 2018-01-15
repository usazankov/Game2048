#ifndef TESTBASEMODEL_H
#define TESTBASEMODEL_H

#include <QObject>
#include "basemodel.h"
class TestBaseModel : public QObject
{
    Q_OBJECT
public:
    explicit TestBaseModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TESTBASEMODEL_H
