#ifndef CTHREAD_H
#define CTHREAD_H

#include <QThread>

class CThread : public QThread
{
	Q_OBJECT

public:
	CThread(QObject *parent);
	~CThread();

private:
	
protected:
	virtual void run();

};

#endif // CTHREAD_H
