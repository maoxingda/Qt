#include "modelview.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ModelView w2;
	w2.show();
	return a.exec();
}
