#pragma once

#include <QWidget>
#include <QEvent>

#define EVENT_SERIAL_SEND	QEvent::Type::User + 1

// 自定义Widget类
class CunstomWid : public QWidget
{
public:
	CunstomWid(QWidget* pParent);
	virtual ~CunstomWid();

protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);

private:
	bool m_bBackground = false;				// 背景图切换标志
};

