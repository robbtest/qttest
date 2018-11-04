#include "CunstomWid.h"
#include <QPainter>
#include <QImage>
#include <QEvent>
#include <QApplication>



CunstomWid::CunstomWid(QWidget* pParent)
	: QWidget(pParent)
{
}


CunstomWid::~CunstomWid()
{
}

void CunstomWid::paintEvent(QPaintEvent *event)
{
	QPainter qcPainter(this);

	if (m_bBackground)
	{
		QImage qcImage(":/DemoPainter1/Resources/11.png");
		qcPainter.drawImage(rect(), qcImage, qcImage.rect());
	}
	else
	{
		QImage qcImage(":/DemoPainter1/Resources/22.png");
		qcPainter.drawImage(rect(), qcImage, qcImage.rect());
	}
	qcPainter.drawRect(rect().adjusted(1,1,-1,-1));

	QWidget::paintEvent(event);
}

void CunstomWid::mousePressEvent(QMouseEvent *event)
{
	m_bBackground = !m_bBackground;
	update();

	QEvent* pEvent = new QEvent(static_cast<QEvent::Type>(EVENT_SERIAL_SEND));
	QApplication::postEvent(parentWidget(), pEvent);

	QWidget::mousePressEvent(event);
}