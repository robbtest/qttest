#include "DemoPainter1.h"
#include <QPainter>
#include <QImage>
#include "CunstomWid.h"
#include "PointData.h"
#include <qt_windows.h>
#include <QDebug>

DemoPainter1::DemoPainter1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.LockedBtn->installEventFilter(this);
	ui.UnlockedBtn->installEventFilter(this);
	ui.LockedBtn->setVisible(true);
	ui.greenBtn->installEventFilter(this);
	ui.blueBtn->installEventFilter(this);

	QWidget* pWid = new QWidget(this);
	pWid->move(660, 22);
	pWid->setFixedHeight(18);
	pWid->setStyleSheet("border:1px solid green");

	qDebug() << "pWid addr is" << pWid;

	connect(this, &DemoPainter1::pointDataUpdate, ui.LineWid, &CunstomWid::updatLine);
	m_dataGenerateThread = std::thread(&DemoPainter1::GenerateData, this);
}

DemoPainter1::~DemoPainter1()
{
	m_bStopThread = true;
	if (m_dataGenerateThread.joinable())
	{
		m_dataGenerateThread.join();
	}
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
	else if (pObj == ui.greenBtn)
	{
		if (pEvent->type() == QEvent::MouseButtonPress)
		{
			ui.LineWid->setLine1Visible(!ui.LineWid->getLine1Visible());
		}
	}
	else if (pObj == ui.blueBtn)
	{
		if (pEvent->type() == QEvent::MouseButtonPress)
		{
			ui.LineWid->setLine2Visible(!ui.LineWid->getLine2Visible());
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

void DemoPainter1::ExecGenerateData()
{
	while (!m_bStopThread)
	{
		ARRAY_TYPE cAarray;
		for (int i = 0; i < 2; i++)
		{
			cAarray.push_back(std::rand() % 100);
		}

		for (auto i : cAarray)
		{   //auto i: ±éÀú
		    qDebug() << i;
		}
		
		Q_SIGNAL(pointDataUpdate(PointData::Instance()->PushPoint(cAarray)));
		Sleep(2000);
	}
}

void DemoPainter1::GenerateData(void* pParam)
{
	DemoPainter1* pDemoPainter1 = static_cast<DemoPainter1*>(pParam);
	
	pDemoPainter1->ExecGenerateData();
}