#include "CallOtherDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CallOtherDemo w;
	w.show();
	return a.exec();
}
