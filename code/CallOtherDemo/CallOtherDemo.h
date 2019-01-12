#pragma once

#include <QtWidgets/QWidget>
#include "ui_CallOtherDemo.h"

#include <thread>

class CallOtherDemo : public QWidget
{
	Q_OBJECT

public:
	CallOtherDemo(QWidget *parent = Q_NULLPTR);
	~CallOtherDemo();

Q_SIGNALS:
	void sigText(QString);

protected:
	// 事件过滤器
	bool eventFilter(QObject* pObj, QEvent* pEvent);
	// 槽函数
	void slotThread(bool bStart);
	void slotText(QString strText);
	// 启动和停止线程
	void StartThread();
	void StopThread();

	// 线程执行体
	void ThreadFuncProc();

private:
	Ui::CallOtherDemoClass  ui;					// 界面
	bool                    m_bExit = true;		// 控制线程退出标志
	std::thread				m_thread;			// 标准线程对象
};
