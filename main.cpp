#include "adapt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	adapt w;
	w.show();
	return a.exec();
}
