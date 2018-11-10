#pragma once

#include <QWidget>
#include <QEvent>
#include "PointData.h"

#define EVENT_SERIAL_SEND	QEvent::Type::User + 1

// �Զ���Widget��
class CunstomWid : public QWidget
{
public:
	CunstomWid(QWidget* pParent);
	virtual ~CunstomWid();

	void setLine1Visible(bool bVisible);
	bool getLine1Visible();
	void setLine2Visible(bool bVisible);
	bool getLine2Visible();

public slots:
	void updatLine(int iIndex);

protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);

private:
	bool		m_bBackground = false;				// ����ͼ�л���־
	ARRAY_TYPE	m_arrLine1;							// ��һ
	ARRAY_TYPE  m_arrLine2;							// �߶�
	bool		m_bLine1 = true;					// ������һ��־
	bool		m_bLine2 = true;					// �����߶���־
};

