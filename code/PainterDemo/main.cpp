#include "DemoPainter1.h"
#include <QtWidgets/QApplication>


#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//在入口函数中包含 _CrtDumpMemoryLeaks();  
//即可检测到内存泄露

//定义函数：
inline void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}
//该函数可以放在主函数的任意位置，都能正确的触发内存泄露输出


int main(int argc, char *argv[])
{
	EnableMemLeakCheck();		//检测是否有内存泄漏
//	_CrtSetBreakAlloc(7498);	//定位内存泄漏位置
	QApplication a(argc, argv);
	DemoPainter1 w;
	w.show();
	return a.exec();
}
