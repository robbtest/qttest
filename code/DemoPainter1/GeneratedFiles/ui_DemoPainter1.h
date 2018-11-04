/********************************************************************************
** Form generated from reading UI file 'DemoPainter1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOPAINTER1_H
#define UI_DEMOPAINTER1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "cunstomwid.h"

QT_BEGIN_NAMESPACE

class Ui_DemoPainter1Wid
{
public:
    CunstomWid *widget;
    QWidget *layoutWidget;
    QHBoxLayout *HLayout1;
    QPushButton *FourStateBtn;
    QPushButton *LockedBtn;
    QPushButton *UnlockedBtn;

    void setupUi(QWidget *DemoPainter1Wid)
    {
        if (DemoPainter1Wid->objectName().isEmpty())
            DemoPainter1Wid->setObjectName(QStringLiteral("DemoPainter1Wid"));
        DemoPainter1Wid->resize(800, 600);
        DemoPainter1Wid->setStyleSheet(QLatin1String("QWidget#DemoPainter1Wid\n"
"{\n"
"	background-color: rgb(158, 136, 140);\n"
"}\n"
"QPushButton#FourStateBtn\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/FourStateBtn_N.png);\n"
"}\n"
"QPushButton#FourStateBtn:hover\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/FourStateBtn_H.png);\n"
"}\n"
"QPushButton#FourStateBtn:pressed\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/FourStateBtn_P.png);\n"
"}\n"
"QPushButton#FourStateBtn:disabled\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/FourStateBtn_D.png);\n"
"}\n"
"\n"
"QPushButton#LockedBtn\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/LockedBtn_N.png);\n"
"}\n"
"QPushButton#LockedBtn:hover\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/LockedBtn_H.png);\n"
"}\n"
"QPushButton#LockedBtn:pressed\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/LockedBtn_P.png);\n"
"}\n"
"\n"
"QPushButton#UnlockedBtn\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/UnlockedBtn_N.png);\n"
"}\n"
"QPushButton#UnlockedBtn:hover\n"
"{"
                        "\n"
"	border-image: url(:/DemoPainter1/Resources/UnlockedBtn_H.png);\n"
"}\n"
"QPushButton#UnlockedBtn:pressed\n"
"{\n"
"	border-image: url(:/DemoPainter1/Resources/UnlockedBtn_P.png);\n"
"}"));
        widget = new CunstomWid(DemoPainter1Wid);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(230, 100, 320, 180));
        layoutWidget = new QWidget(DemoPainter1Wid);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 102, 20));
        HLayout1 = new QHBoxLayout(layoutWidget);
        HLayout1->setSpacing(0);
        HLayout1->setContentsMargins(11, 11, 11, 11);
        HLayout1->setObjectName(QStringLiteral("HLayout1"));
        HLayout1->setSizeConstraint(QLayout::SetMinimumSize);
        HLayout1->setContentsMargins(0, 0, 0, 0);
        FourStateBtn = new QPushButton(layoutWidget);
        FourStateBtn->setObjectName(QStringLiteral("FourStateBtn"));
        FourStateBtn->setMinimumSize(QSize(40, 18));
        FourStateBtn->setMaximumSize(QSize(40, 18));

        HLayout1->addWidget(FourStateBtn);

        LockedBtn = new QPushButton(layoutWidget);
        LockedBtn->setObjectName(QStringLiteral("LockedBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LockedBtn->sizePolicy().hasHeightForWidth());
        LockedBtn->setSizePolicy(sizePolicy);
        LockedBtn->setMinimumSize(QSize(18, 18));
        LockedBtn->setMaximumSize(QSize(18, 18));

        HLayout1->addWidget(LockedBtn);

        UnlockedBtn = new QPushButton(layoutWidget);
        UnlockedBtn->setObjectName(QStringLiteral("UnlockedBtn"));
        sizePolicy.setHeightForWidth(UnlockedBtn->sizePolicy().hasHeightForWidth());
        UnlockedBtn->setSizePolicy(sizePolicy);
        UnlockedBtn->setMinimumSize(QSize(18, 18));
        UnlockedBtn->setMaximumSize(QSize(18, 18));

        HLayout1->addWidget(UnlockedBtn);


        retranslateUi(DemoPainter1Wid);

        QMetaObject::connectSlotsByName(DemoPainter1Wid);
    } // setupUi

    void retranslateUi(QWidget *DemoPainter1Wid)
    {
        DemoPainter1Wid->setWindowTitle(QApplication::translate("DemoPainter1Wid", "DemoPainter1", 0));
        FourStateBtn->setText(QString());
        LockedBtn->setText(QString());
        UnlockedBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DemoPainter1Wid: public Ui_DemoPainter1Wid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOPAINTER1_H
