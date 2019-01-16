#include "modelview.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ModelView w1;
	w1.show();
	return a.exec();
}
