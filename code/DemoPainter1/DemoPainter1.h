#pragma once

#include <QtWidgets/QWidget>
#include "ui_DemoPainter1.h"
#include <thread>
#include <mutex>

class DemoPainter1 : public QWidget
{
	Q_OBJECT

public:
	DemoPainter1(QWidget *parent = Q_NULLPTR);
	~DemoPainter1();

signals:
	void pointDataUpdate(int iIndex);

protected:
	bool eventFilter(QObject* pObj, QEvent* pEvent);
	void paintEvent(QPaintEvent *pEvent);
	void customEvent(QEvent *pEvent);

	void ExecGenerateData();

	static void GenerateData(void* pParam);

private:
	Ui::DemoPainter1Wid ui;								// ����
	int					m_iSerialSendCount  = 0;		// ���մ��ڷ����¼�����
	bool				m_bStopThread		= false;	// ֹͣ�̱߳�־
	std::thread			m_dataGenerateThread;			// ���������߳�		
};
