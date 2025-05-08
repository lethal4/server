/********************************************************************************
** Form generated from reading UI file 'findsuccessdg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDSUCCESSDG_H
#define UI_FINDSUCCESSDG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickbtn.h>

QT_BEGIN_NAMESPACE

class Ui_findSuccessDg
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *head_lb;
    QLabel *name_lb;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    clickBtn *add_friend_btn;

    void setupUi(QDialog *findSuccessDg)
    {
        if (findSuccessDg->objectName().isEmpty())
            findSuccessDg->setObjectName("findSuccessDg");
        findSuccessDg->resize(300, 200);
        findSuccessDg->setMinimumSize(QSize(300, 200));
        findSuccessDg->setMaximumSize(QSize(300, 200));
        verticalLayout = new QVBoxLayout(findSuccessDg);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(findSuccessDg);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        head_lb = new QLabel(widget);
        head_lb->setObjectName("head_lb");
        head_lb->setMinimumSize(QSize(50, 50));
        head_lb->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(head_lb);

        name_lb = new QLabel(widget);
        name_lb->setObjectName("name_lb");

        horizontalLayout->addWidget(name_lb);

        horizontalSpacer = new QSpacerItem(157, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(findSuccessDg);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        add_friend_btn = new clickBtn(widget_2);
        add_friend_btn->setObjectName("add_friend_btn");
        add_friend_btn->setMinimumSize(QSize(130, 0));
        add_friend_btn->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_2->addWidget(add_friend_btn);


        verticalLayout->addWidget(widget_2);


        retranslateUi(findSuccessDg);

        QMetaObject::connectSlotsByName(findSuccessDg);
    } // setupUi

    void retranslateUi(QDialog *findSuccessDg)
    {
        findSuccessDg->setWindowTitle(QCoreApplication::translate("findSuccessDg", "Dialog", nullptr));
        head_lb->setText(QString());
        name_lb->setText(QCoreApplication::translate("findSuccessDg", "\345\220\215\347\247\260", nullptr));
        add_friend_btn->setText(QCoreApplication::translate("findSuccessDg", "\346\267\273\345\212\240\345\210\260\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class findSuccessDg: public Ui_findSuccessDg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDSUCCESSDG_H
