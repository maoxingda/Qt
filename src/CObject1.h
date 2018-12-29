#ifndef COBJECT1_H
#define COBJECT1_H

#include <QObject>
#include "CStudent.h"

class CObject1 : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit CObject1(QObject *parent = nullptr);

	static CObject1* self;

signals:
	void signal01(Student);

public slots:
	void slot01();
	void emitSignals();
};

#endif // COBJECT1_H