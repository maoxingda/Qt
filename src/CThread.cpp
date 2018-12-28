#include "CThread.h"
#include "CObject2.h"
#include <QCoreApplication>
#include "CObject1.h"

CThread::CThread(QObject *parent)
	: QThread(parent)
{

}

CThread::~CThread()
{

}

void CThread::run()
{
	CObject1::self->emitSignals();
}
