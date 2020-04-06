#include "CallOtherDemo.h"

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QScrollBar>

#ifdef WIN32
#include <qt_windows.h>
#endif

CallOtherDemo::CallOtherDemo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.ThreadControlWid->setCheckable(true);
	QString strText = !ui.ThreadControlWid->isChecked() ? "Start" : "Stop";
	ui.ThreadControlWid->setText(strText);

	ui.CallDemoWid->installEventFilter(this);

	connect(ui.ThreadControlWid, &QPushButton::clicked, this, &CallOtherDemo::slotThread);
	connect(this, &CallOtherDemo::sigText, this, &CallOtherDemo::slotText);
}

CallOtherDemo::~CallOtherDemo()
{
	StopThread();
}

bool CallOtherDemo::eventFilter(QObject* pObj, QEvent* pEvent)
{
	if (pObj == ui.CallDemoWid)
	{
		if (pEvent->type() == QEvent::MouseButtonRelease)
		{
#if WIN32
			char szFileName[512] = { 0 };
			::GetModuleFileNameA(NULL, szFileName, MAX_PATH);
			*strrchr(szFileName, '\\') = '\0';
			strcat(szFileName, "\\PainterDemo.exe");
			::ShellExecuteA(NULL, "open", szFileName, "", NULL, SW_SHOW);
#endif
		}
	}
	return QWidget::eventFilter(pObj, pEvent);
}

void CallOtherDemo::slotThread(bool bStart)
{
	ui.ThreadControlWid->setEnabled(false);

	bStart ? StartThread() : StopThread();
	if (bStart)
	{
		ui.ThreadTextWid->setPlainText("");
	}

	QString strText = !bStart ? "Start" : "Stop";
	ui.ThreadControlWid->setText(strText);
	ui.ThreadControlWid->setEnabled(true);
}

void CallOtherDemo::slotText(QString strText)
{
	ui.ThreadTextWid->setPlainText(ui.ThreadTextWid->toPlainText() + strText + "\n");

	QScrollBar *scrollbar = ui.ThreadTextWid->verticalScrollBar();
	if (scrollbar)
	{
		scrollbar->setSliderPosition(scrollbar->maximum());
	}
}

/*
	@说明 joinable() -> 查看线程是否活跃，即是否在执行函数体
	      join()     -> 等待线程执行完成和退出，即阻塞在此处
		  m_bExit    -> 控制线程中循环体是否退出标志 true表示退出循环体
*/
void CallOtherDemo::StartThread()
{
	if (m_bExit)
	{
		m_bExit = false;
		if (m_thread.joinable())
		{
			m_thread.join();
		}
		m_thread = std::thread(&CallOtherDemo::ThreadFuncProc, this);
		//std::thread m_thread(&CallOtherDemo::ThreadFuncProc, this);	//线程已经定义,这里会重复定义
	}
}

void CallOtherDemo::StopThread()
{
	if (!m_bExit)
	{
		m_bExit = true;
		m_thread.join();
	}
}

void CallOtherDemo::ThreadFuncProc()
{
	int iCount = 0;

	while (!m_bExit)
	{
		iCount++;
		QString str = QString("The %1th time: %2").arg(iCount, 3).arg(QTime::currentTime().toString("HH:mm:ss"));
		QThread::msleep(500);
		
		emit sigText(str);
	}

	m_bExit = true;
}
