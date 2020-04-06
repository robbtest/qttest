#include "DemoPainter1.h"
#include <QtWidgets/QApplication>


#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  

//
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DemoPainter1 w;
	w.show();
	return a.exec();
}
