#include "CallOtherDemo.h"

#include <qt_windows.h>

CallOtherDemo::CallOtherDemo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.CallDemoWid->installEventFilter(this);
}

bool CallOtherDemo::eventFilter(QObject* pObj, QEvent* pEvent)
{
	if (pObj == ui.CallDemoWid)
	{
		if (pEvent->type() == QEvent::MouseButtonRelease)
		{
			//::ShellExecute(winId(),"DemoPainter1.exe",);
			::ShellExecute(NULL, L"open", L"DemoPainter1.exe", L"", NULL, SW_SHOW);
		}
	}
	return QWidget::eventFilter(pObj, pEvent);
}