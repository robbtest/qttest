#include "CallOtherDemo.h"

#include <qt_windows.h>

CallOtherDemo::CallOtherDemo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.CallDemoWid->installEventFilter(this);
}
#include <tchar.h>
bool CallOtherDemo::eventFilter(QObject* pObj, QEvent* pEvent)
{
	if (pObj == ui.CallDemoWid)
	{
		if (pEvent->type() == QEvent::MouseButtonRelease)
		{
			char szFileName[512] = { 0 };
			::GetModuleFileNameA(NULL, szFileName, MAX_PATH);
			*strrchr(szFileName, '\\') = '\0';
			strcat(szFileName, "\\PainterDemo.exe");
			::ShellExecuteA(NULL, "open", szFileName, "", NULL, SW_SHOW);
		}
	}
	return QWidget::eventFilter(pObj, pEvent);
}