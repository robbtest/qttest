#include "DemoPainter1.h"
#include <QtWidgets/QApplication>


#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//����ں����а��� _CrtDumpMemoryLeaks();  
//���ɼ�⵽�ڴ�й¶

//���庯����
inline void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}
//�ú������Է���������������λ�ã�������ȷ�Ĵ����ڴ�й¶���


int main(int argc, char *argv[])
{
	EnableMemLeakCheck();		//����Ƿ����ڴ�й©
//	_CrtSetBreakAlloc(7498);	//��λ�ڴ�й©λ��
	QApplication a(argc, argv);
	DemoPainter1 w;
	w.show();
	return a.exec();
}
