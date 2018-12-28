#ifndef COBJECT3_H
#define COBJECT3_H

#include <QObject>

class CObject3 : public QObject
{
	Q_OBJECT
public:
	CObject3(QObject *parent = nullptr);
	~CObject3();

//signals:
	void signal1();

private:
	/*Q_INVOKABLE */void invokableMethod();
	
//private slots:
	void slot1();
};

#endif // COBJECT3_H
