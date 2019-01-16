#include "modelview.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ModelView w11;
	w11.show();
	return a.exec();
}
