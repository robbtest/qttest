#pragma once

#include <QtWidgets/QWidget>
#include "ui_DemoPainter1.h"

class DemoPainter1 : public QWidget
{
	Q_OBJECT

public:
	DemoPainter1(QWidget *parent = Q_NULLPTR);

protected:
	bool eventFilter(QObject* pObj, QEvent* pEvent);
	void paintEvent(QPaintEvent *pEvent);
	void customEvent(QEvent *pEvent);

private:
	Ui::DemoPainter1Wid ui;								// 界面
	int					m_iSerialSendCount = 0;			// 接收串口发送事件次数
};
