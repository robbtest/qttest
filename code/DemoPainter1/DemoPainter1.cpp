#include "DemoPainter1.h"
#include <QPainter>
#include <QImage>
#include "CunstomWid.h"

DemoPainter1::DemoPainter1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.LockedBtn->installEventFilter(this);
	ui.UnlockedBtn->installEventFilter(this);
	ui.LockedBtn->setVisible(false);

	QWidget* pWid = new QWidget(this);
	pWid->move(660, 22);
	pWid->setFixedHeight(18);
	pWid->setStyleSheet("border:1px solid green");
	
}

bool DemoPainter1::eventFilter(QObject* pObj, QEvent* pEvent)
{
	if (pObj == ui.LockedBtn)
	{
		if (pEvent->type() == QEvent::MouseButtonRelease)
		{
			ui.LockedBtn->setVisible(false);
			ui.UnlockedBtn->setVisible(true);
			ui.FourStateBtn->setEnabled(true);
		}
	}
	else if (pObj == ui.UnlockedBtn)
	{
		if (pEvent->type() == QEvent::MouseButtonRelease)
		{
			ui.LockedBtn->setVisible(true);
			ui.UnlockedBtn->setVisible(false);
			ui.FourStateBtn->setEnabled(false);
		}
	}
	return QWidget::eventFilter(pObj, pEvent);
}

void DemoPainter1::paintEvent(QPaintEvent *pEvent)
{
	QPainter qcPainter(this);
	// »æÖÆÏß
	qcPainter.drawLine(QPoint(30, 50), QPoint(770, 50));
	//
	if (m_iSerialSendCount > 0)
	{
		qcPainter.drawText(QPoint(30, 64), QString("receiver serial event : %1").arg(m_iSerialSendCount));
	}

	QWidget::paintEvent(pEvent);
}

void DemoPainter1::customEvent(QEvent *pEvent)
{
	if (pEvent->type() == EVENT_SERIAL_SEND)
	{
		++m_iSerialSendCount;
		update();
	}
}

