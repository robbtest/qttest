#pragma once

#ifndef _DEMOPAINTER1_H_
#define _DEMOPAINTER1_H_

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
	Ui::DemoPainter1Wid ui;								// 界面
	int					m_iSerialSendCount  = 0;		// 接收串口发送事件次数
	bool				m_bStopThread		= false;	// 停止线程标志
	std::thread			m_dataGenerateThread;			// 数据生成线程		
};

#endif // _DEMOPAINTER1_H_
