#include "CObject1.h"
#include <QTimer>

CObject1* CObject1::self = nullptr;

CObject1::CObject1(QObject *parent) : QObject(parent)
{
	self = this;
}

void CObject1::slot01()
{

}

void CObject1::emitSignals()
{
	Student stu;
	stu.name	= "maoxd";
	stu.id		= 1;
	emit signal01(stu);
}
