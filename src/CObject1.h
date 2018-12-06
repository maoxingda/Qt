#ifndef COBJECT1_H
#define COBJECT1_H

#include <QObject>

class CObject1 : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit CObject1(QObject *parent = nullptr);

signals:
	void signal1();
	void signal2();

public slots:
	void emitSignals();
};

#endif // COBJECT1_H