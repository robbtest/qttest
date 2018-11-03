#pragma once

#include <QtWidgets/QWidget>
#include "ui_DemoPainter1.h"

class DemoPainter1 : public QWidget
{
	Q_OBJECT

public:
	DemoPainter1(QWidget *parent = Q_NULLPTR);

private:
	Ui::DemoPainter1Class ui;
};
