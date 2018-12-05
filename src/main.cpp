#include <QCoreApplication>
#include "CObject1.h"
#include "CObject2.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	CObject1 obj1(&a);
	CObject2 obj2(&a);

	QObject::connect(&obj1, SIGNAL(signal1()), &obj2, SLOT(slot1()));
	QObject::connect(&obj1, SIGNAL(signal2()), &obj2, SLOT(slot2()));

    return a.exec();
}
