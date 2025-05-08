/********************************************************************************
** Form generated from reading UI file 'conuseritem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONUSERITEM_H
#define UI_CONUSERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conUserItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QLabel *icon_lb;
    QLabel *red_point;
    QLabel *username_lb;

    void setupUi(QWidget *conUserItem)
    {
        if (conUserItem->objectName().isEmpty())
            conUserItem->setObjectName("conUserItem");
        conUserItem->resize(400, 75);
        conUserItem->setMinimumSize(QSize(0, 75));
        conUserItem->setMaximumSize(QSize(16777215, 75));
        horizontalLayout = new QHBoxLayout(conUserItem);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(conUserItem);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(62, 62));
        widget->setMaximumSize(QSize(62, 62));
        icon_lb = new QLabel(widget);
        icon_lb->setObjectName("icon_lb");
        icon_lb->setGeometry(QRect(3, 15, 46, 46));
        icon_lb->setMinimumSize(QSize(46, 46));
        icon_lb->setMaximumSize(QSize(46, 46));
        red_point = new QLabel(widget);
        red_point->setObjectName("red_point");
        red_point->setGeometry(QRect(27, 2, 30, 30));
        red_point->setMinimumSize(QSize(30, 30));
        red_point->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(widget);

        username_lb = new QLabel(conUserItem);
        username_lb->setObjectName("username_lb");

        horizontalLayout->addWidget(username_lb);


        retranslateUi(conUserItem);

        QMetaObject::connectSlotsByName(conUserItem);
    } // setupUi

    void retranslateUi(QWidget *conUserItem)
    {
        conUserItem->setWindowTitle(QCoreApplication::translate("conUserItem", "Form", nullptr));
        icon_lb->setText(QString());
        red_point->setText(QString());
        username_lb->setText(QCoreApplication::translate("conUserItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conUserItem: public Ui_conUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONUSERITEM_H
