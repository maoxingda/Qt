#ifndef COBJECT2_H
#define COBJECT2_H

#include <QObject>
#include "CStudent.h"

class CObject2 : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit CObject2(QObject *parent = nullptr);

signals:
	void signal01();

public slots:
	void slot01(Student);
};

#endif // COBJECT2_H