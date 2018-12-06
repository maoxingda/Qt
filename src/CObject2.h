#ifndef COBJECT2_H
#define COBJECT2_H

#include <QObject>

class CObject2 : public QObject
{
    Q_OBJECT
public:
    explicit CObject2(QObject *parent = nullptr);

signals:

public slots:
	void slot1();
	void slot2();
	void on_obj2_signal1();
	void on_obj2_signal2();
};

#endif // COBJECT2_H