#include "CObject1.h"
#include <QTimer>

CObject1::CObject1(QObject *parent) : QObject(parent)
{
	QTimer::singleShot(3000, this, SLOT(emitSignals()));
}

void CObject1::emitSignals()
{
	emit signal1();
	emit signal2();
}
