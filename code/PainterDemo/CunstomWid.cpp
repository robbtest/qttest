#include "CunstomWid.h"
#include <QPainter>
#include <QImage>
#include <QEvent>
#include <QApplication>



CunstomWid::CunstomWid(QWidget* pParent)
	: QWidget(pParent)
{
	m_arrLine1.reserve(21);
	m_arrLine2.reserve(21);
}


CunstomWid::~CunstomWid()
{
}

void CunstomWid::setLine1Visible(bool bVisible)
{
	if (m_bLine1 != bVisible)
	{
		m_bLine1 = bVisible;
		update();
	}
}

bool CunstomWid::getLine1Visible()
{
	return m_bLine1;
}

void CunstomWid::setLine2Visible(bool bVisible)
{
	if (m_bLine2 != bVisible)
	{
		m_bLine2 = bVisible;
		update();
	}
}

bool CunstomWid::getLine2Visible()
{
	return m_bLine2;
}

void CunstomWid::updatLine(int iIndex)
{
	ARRAY_TYPE arr1 = PointData::Instance()->PopPoint(iIndex);
	if (m_arrLine1.size()>=20)
		m_arrLine1.pop_back();
	m_arrLine1.insert(m_arrLine1.begin(), arr1.at(0));
	if (m_arrLine2.size() >= 20)
		m_arrLine2.pop_back();
	m_arrLine2.insert(m_arrLine2.begin(), arr1.at(1));

	update();
}

void CunstomWid::paintEvent(QPaintEvent *event)
{
	QPainter qcPainter(this);
	// 绘制边框
	qcPainter.setPen(QColor(110, 110, 110));
	qcPainter.drawRect(rect().adjusted(1, 1, -1, -1));
	// 绘制背景图
	if (m_bBackground)
	{
		QImage qcImage(":/DemoPainter1/Resources/11.png");
		qcPainter.drawImage(rect(), qcImage, qcImage.rect());
	}
	else
	{
		//QImage qcImage(":/DemoPainter1/Resources/22.png");
		//qcPainter.drawImage(rect(), qcImage, qcImage.rect());
	}
	// 绘制坐标
	qcPainter.setPen(QColor(90, 70, 70));
	qcPainter.drawLine(QPoint(30,470), QPoint(30,40));
	qcPainter.drawLine(QPoint(30, 470), QPoint(720, 470));
	// 绘制线1
	qcPainter.setPen(Qt::green);
	if (m_arrLine1.size() > 2 && m_bLine1)
	{
		int iX = 30;
		int iY = m_arrLine1.at(0);
		for (int i = 1; i < m_arrLine1.size(); i++)
		{
			int iNextX = iX + 35;
			qcPainter.drawLine(QPoint(iX, 430 - 430 * iY / 100 + 40), QPoint(iNextX, 430 - 430 * m_arrLine1.at(i) / 100 + 40));
			iX = iNextX;
			iY = m_arrLine1.at(i);
		}
	}
	// 绘制线2
	qcPainter.setPen(Qt::blue);
	if (m_arrLine2.size() > 2 && m_bLine2)
	{
		int iX = 30;
		int iY = m_arrLine2.at(0);
		for (int i = 1; i < m_arrLine2.size(); i++)
		{
			int iNextX = iX + 35;
			qcPainter.drawLine(QPoint(iX, 430 - 430 * iY / 100 + 40), QPoint(iNextX, 430 - 430 * m_arrLine2.at(i) / 100 + 40));
			iX = iNextX;
			iY = m_arrLine2.at(i);
		}
	}

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