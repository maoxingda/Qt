#include <QCoreApplication>
#include "CObject1.h"
#include "CObject2.h"
#include "CObject3.h"
#include <QMetaMethod>
#include "CThread.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	qRegisterMetaType<Student>("Student");

	CThread thrd1(nullptr);
	thrd1.start();

	CObject1* obj1 = new CObject1(qApp);
	CObject2* obj2 = new CObject2(qApp);

	QObject::connect(obj1, SIGNAL(signal01(Student)), obj2, SLOT(slot01(Student)));

    return a.exec();
}
