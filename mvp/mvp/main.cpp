#include "mvp.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mvp w;
	w.show();

	return a.exec();
}
