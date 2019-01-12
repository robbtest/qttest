#include "CallOtherDemo.h"

#include <qt_windows.h>
#include <QDebug>
#include <QTime>
#include <QThread>
#include <QScrollBar>

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
			char szFileName[512] = { 0 };
			::GetModuleFileNameA(NULL, szFileName, MAX_PATH);
			*strrchr(szFileName, '\\') = '\0';
			strcat(szFileName, "\\PainterDemo.exe");
			::ShellExecuteA(NULL, "open", szFileName, "", NULL, SW_SHOW);
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
	@˵�� joinable() -> �鿴�߳��Ƿ��Ծ�����Ƿ���ִ�к�����
	      join()     -> �ȴ��߳�ִ����ɺ��˳����������ڴ˴�
		  m_bExit    -> �����߳���ѭ�����Ƿ��˳���־ true��ʾ�˳�ѭ����
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