#include "CObject1.h"
#include <QTimer>

CObject1::CObject1(QObject *parent) : QObject(parent)
{
	self = this;
	//QTimer::singleShot(20, this, SLOT(emitSignals()));
}

CObject1* CObject1::self = nullptr;

void CObject1::slot01()
{

}

void CObject1::slot02()
{

}

void CObject1::slot03()
{

}

void CObject1::emitSignals()
{
	Student stu;
	stu.name	= "maoxd";
	stu.id		= 1;
	emit signal01(stu);
}
