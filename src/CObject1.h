#ifndef COBJECT1_H
#define COBJECT1_H

#include <QObject>
#include "CStudent.h"

class CObject1 : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit CObject1(QObject *parent = nullptr);

	static CObject1* self;

public slots:
	void slot01();
	void slot02();
	void slot03();

signals:
	void signal01(Student);
	void signal02();
	void signal03();
	void signal04();
	void signal05();
	void signal06();
	void signal07();
	void signal08();
	void signal09();
	void signal10();
	void signal11();
	void signal12();
	void signal13();
	void signal14();
	void signal15();
	void signal16();
	void signal17();
	void signal18();
	void signal19();
	void signal20();
	void signal21();
	void signal22();
	void signal23();
	void signal24();
	void signal25();
	void signal26();
	void signal27();
	void signal28();
	void signal29();
	void signal30();
	void signal31();
	void signal32();
	void signal33();
	void signal34();
	void signal35();
	void signal36();
	void signal37();
	void signal38();
	void signal39();
	void signal40();
	void signal41();
	void signal42();
	void signal43();
	void signal44();
	void signal45();
	void signal46();
	void signal47();
	void signal48();
	void signal49();
	void signal50();
	void signal51();
	void signal52();
	void signal53();
	void signal54();
	void signal55();
	void signal56();
	void signal57();
	void signal58();
	void signal59();
	void signal60();
	void signal61();
	void signal62();
	void signal63();
	void signal64();

public slots:
	void emitSignals();
};

#endif // COBJECT1_H