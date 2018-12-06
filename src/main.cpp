#include <QCoreApplication>
#include "CObject1.h"
#include "CObject2.h"
#include "CObject3.h"
#include <QMetaMethod>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	CObject2 obj2(&a);
	CObject1 obj1(&obj2);
	CObject3 obj3;
	const QMetaObject* mo = obj3.metaObject();
	obj1.setObjectName(QString::fromLocal8Bit("obj2"));

	//QMetaObject::connectSlotsByName(&obj2);
	QObject::connect(&obj1, SIGNAL(signal1()), &obj2, SLOT(slot1()));
	//QObject::connect(&obj1, SIGNAL(signal2()), &obj2, SLOT(slot2()));

	int mc = obj3.metaObject()->methodCount();

	QMetaMethod mm = obj3.metaObject()->method(4);

	mm.invoke(&obj3);

    return a.exec();
}
