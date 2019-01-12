#pragma once

#include <QtWidgets/QWidget>
#include "ui_CallOtherDemo.h"

#include <thread>

class CallOtherDemo : public QWidget
{
	Q_OBJECT

public:
	CallOtherDemo(QWidget *parent = Q_NULLPTR);
	~CallOtherDemo();

Q_SIGNALS:
	void sigText(QString);

protected:
	// �¼�������
	bool eventFilter(QObject* pObj, QEvent* pEvent);
	// �ۺ���
	void slotThread(bool bStart);
	void slotText(QString strText);
	// ������ֹͣ�߳�
	void StartThread();
	void StopThread();

	// �߳�ִ����
	void ThreadFuncProc();

private:
	Ui::CallOtherDemoClass  ui;					// ����
	bool                    m_bExit = true;		// �����߳��˳���־
	std::thread				m_thread;			// ��׼�̶߳���
};
