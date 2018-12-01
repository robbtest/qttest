#pragma once

#include <QWidget>
#include <QEvent>
#include <QMenu>
#include "PointData.h"

#define EVENT_SERIAL_SEND	QEvent::Type::User + 1

// 自定义Widget类
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
	bool		m_bBackground = false;				// 背景图切换标志
	ARRAY_TYPE	m_arrLine1;							// 线一
	ARRAY_TYPE  m_arrLine2;							// 线二
	bool		m_bLine1 = true;					// 绘制线一标志
	bool		m_bLine2 = true;					// 绘制线二标志
	QMenu*		m_pMenu  = nullptr;					// 菜单
};

