#pragma once

#include <QtWidgets/QWidget>
#include "ui_CallOtherDemo.h"

class CallOtherDemo : public QWidget
{
	Q_OBJECT

public:
	CallOtherDemo(QWidget *parent = Q_NULLPTR);

protected:
	bool CallOtherDemo::eventFilter(QObject* pObj, QEvent* pEvent);

private:
	Ui::CallOtherDemoClass ui;
};
