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

	//obj1->blockSignals(true);

	//for (auto i = 1; i < 10; ++i)
	//{
	//	QString order	= QString::number(i);
	//	QString signal	= QString::fromAscii("2signal0%1").arg(order);
	//	QString slot	= QString::fromAscii("1slot0%1").arg(order);

	//	QObject::connect(obj1, signal.toAscii().data(), obj2, slot.toAscii().data());
	//}

	//connects
	//1---->1
	//1---->2
	//1---->3
	QObject::connect(obj1, SIGNAL(signal01(Student)), obj2, SLOT(slot01(Student)));
	/*QObject::connect(obj1, SIGNAL(signal01()), obj2, SLOT(slot01()));
	QObject::connect(obj1, SIGNAL(signal01()), obj2, SLOT(slot02()));
	QObject::connect(obj1, SIGNAL(signal01()), obj2, SLOT(slot03()));
	QObject::connect(obj2, SIGNAL(signal01()), obj1, SLOT(slot01()));
	QObject::connect(obj2, SIGNAL(signal02()), obj1, SLOT(slot01()));
	QObject::connect(obj2, SIGNAL(signal03()), obj1, SLOT(slot01()));*/
	//QObject::connect(obj1, SIGNAL(signal01()), obj2, SLOT(slot01()));
	//QObject::connect(obj1, SIGNAL(signal02()), obj2, SLOT(slot02()));
	//QObject::connect(obj1, SIGNAL(signal03()), obj2, SLOT(slot03()));
	//QObject::connect(obj1, SIGNAL(signal04()), obj2, SLOT(slot04()));
	//QObject::connect(obj1, SIGNAL(signal05()), obj2, SLOT(slot05()));
	//QObject::connect(obj1, SIGNAL(signal06()), obj2, SLOT(slot06()));
	//QObject::connect(obj1, SIGNAL(signal07()), obj2, SLOT(slot07()));
	//QObject::connect(obj1, SIGNAL(signal08()), obj2, SLOT(slot08()));
	//QObject::connect(obj1, SIGNAL(signal09()), obj2, SLOT(slot09()));
	//QObject::connect(obj1, SIGNAL(signal10()), obj2, SLOT(slot10()));
	//QObject::connect(obj1, SIGNAL(signal11()), obj2, SLOT(slot11()));
	//QObject::connect(obj1, SIGNAL(signal12()), obj2, SLOT(slot12()));
	//QObject::connect(obj1, SIGNAL(signal13()), obj2, SLOT(slot13()));
	//QObject::connect(obj1, SIGNAL(signal14()), obj2, SLOT(slot14()));
	//QObject::connect(obj1, SIGNAL(signal15()), obj2, SLOT(slot15()));
	//QObject::connect(obj1, SIGNAL(signal16()), obj2, SLOT(slot16()));
	//QObject::connect(obj1, SIGNAL(signal17()), obj2, SLOT(slot17()));
	//QObject::connect(obj1, SIGNAL(signal18()), obj2, SLOT(slot18()));
	//QObject::connect(obj1, SIGNAL(signal19()), obj2, SLOT(slot19()));
	//QObject::connect(obj1, SIGNAL(signal20()), obj2, SLOT(slot20()));
	//QObject::connect(obj1, SIGNAL(signal21()), obj2, SLOT(slot21()));
	//QObject::connect(obj1, SIGNAL(signal22()), obj2, SLOT(slot22()));
	//QObject::connect(obj1, SIGNAL(signal23()), obj2, SLOT(slot23()));
	//QObject::connect(obj1, SIGNAL(signal24()), obj2, SLOT(slot24()));
	//QObject::connect(obj1, SIGNAL(signal25()), obj2, SLOT(slot25()));
	//QObject::connect(obj1, SIGNAL(signal26()), obj2, SLOT(slot26()));
	//QObject::connect(obj1, SIGNAL(signal27()), obj2, SLOT(slot27()));
	//QObject::connect(obj1, SIGNAL(signal28()), obj2, SLOT(slot28()));
	//QObject::connect(obj1, SIGNAL(signal29()), obj2, SLOT(slot29()));
	//QObject::connect(obj1, SIGNAL(signal30()), obj2, SLOT(slot30()));
	//QObject::connect(obj1, SIGNAL(signal31()), obj2, SLOT(slot31()));
	//QObject::connect(obj1, SIGNAL(signal32()), obj2, SLOT(slot32()));
	//QObject::connect(obj1, SIGNAL(signal33()), obj2, SLOT(slot33()));
	//QObject::connect(obj1, SIGNAL(signal34()), obj2, SLOT(slot34()));
	//QObject::connect(obj1, SIGNAL(signal35()), obj2, SLOT(slot35()));
	//QObject::connect(obj1, SIGNAL(signal36()), obj2, SLOT(slot36()));
	//QObject::connect(obj1, SIGNAL(signal37()), obj2, SLOT(slot37()));
	//QObject::connect(obj1, SIGNAL(signal38()), obj2, SLOT(slot38()));
	//QObject::connect(obj1, SIGNAL(signal39()), obj2, SLOT(slot39()));
	//QObject::connect(obj1, SIGNAL(signal40()), obj2, SLOT(slot40()));
	//QObject::connect(obj1, SIGNAL(signal41()), obj2, SLOT(slot41()));
	//QObject::connect(obj1, SIGNAL(signal42()), obj2, SLOT(slot42()));
	//QObject::connect(obj1, SIGNAL(signal43()), obj2, SLOT(slot43()));
	//QObject::connect(obj1, SIGNAL(signal44()), obj2, SLOT(slot44()));
	//QObject::connect(obj1, SIGNAL(signal45()), obj2, SLOT(slot45()));
	//QObject::connect(obj1, SIGNAL(signal46()), obj2, SLOT(slot46()));
	//QObject::connect(obj1, SIGNAL(signal47()), obj2, SLOT(slot47()));
	//QObject::connect(obj1, SIGNAL(signal48()), obj2, SLOT(slot48()));
	//QObject::connect(obj1, SIGNAL(signal49()), obj2, SLOT(slot49()));
	//QObject::connect(obj1, SIGNAL(signal50()), obj2, SLOT(slot50()));
	//QObject::connect(obj1, SIGNAL(signal51()), obj2, SLOT(slot51()));
	//QObject::connect(obj1, SIGNAL(signal52()), obj2, SLOT(slot52()));
	//QObject::connect(obj1, SIGNAL(signal53()), obj2, SLOT(slot53()));
	//QObject::connect(obj1, SIGNAL(signal54()), obj2, SLOT(slot54()));
	//QObject::connect(obj1, SIGNAL(signal55()), obj2, SLOT(slot55()));
	//QObject::connect(obj1, SIGNAL(signal56()), obj2, SLOT(slot56()));
	//QObject::connect(obj1, SIGNAL(signal57()), obj2, SLOT(slot57()));
	//QObject::connect(obj1, SIGNAL(signal58()), obj2, SLOT(slot58()));
	//QObject::connect(obj1, SIGNAL(signal59()), obj2, SLOT(slot59()));
	//QObject::connect(obj1, SIGNAL(signal60()), obj2, SLOT(slot60()));
	//QObject::connect(obj1, SIGNAL(signal61()), obj2, SLOT(slot61()));
	//QObject::connect(obj1, SIGNAL(signal62()), obj2, SLOT(slot62()));
	//QObject::connect(obj1, SIGNAL(signal63()), obj2, SLOT(slot63()));
	//QObject::connect(obj1, SIGNAL(signal64()), obj2, SLOT(slot64()));

	//obj1->dumpObjectInfo();
	obj2->dumpObjectInfo();

    return a.exec();
}
