/********************************************************************************
** Form generated from reading UI file 'applyfrienditem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYFRIENDITEM_H
#define UI_APPLYFRIENDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickbtn.h>

QT_BEGIN_NAMESPACE

class Ui_applyFriendItem
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *icon_lb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *user_name_lb;
    QLabel *user_chat_lb;
    QSpacerItem *horizontalSpacer_3;
    clickBtn *addBtn;
    QLabel *already_add_lb;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *applyFriendItem)
    {
        if (applyFriendItem->objectName().isEmpty())
            applyFriendItem->setObjectName("applyFriendItem");
        applyFriendItem->resize(521, 80);
        applyFriendItem->setMinimumSize(QSize(0, 80));
        applyFriendItem->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(applyFriendItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(3, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        icon_lb = new QLabel(applyFriendItem);
        icon_lb->setObjectName("icon_lb");
        icon_lb->setMinimumSize(QSize(45, 45));
        icon_lb->setMaximumSize(QSize(45, 45));

        horizontalLayout->addWidget(icon_lb);

        widget = new QWidget(applyFriendItem);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 1, -1, 1);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        user_name_lb = new QLabel(widget_2);
        user_name_lb->setObjectName("user_name_lb");
        user_name_lb->setMinimumSize(QSize(100, 0));

        verticalLayout->addWidget(user_name_lb);

        user_chat_lb = new QLabel(widget_2);
        user_chat_lb->setObjectName("user_chat_lb");
        user_chat_lb->setMinimumSize(QSize(100, 0));

        verticalLayout->addWidget(user_chat_lb);


        horizontalLayout_2->addWidget(widget_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        addBtn = new clickBtn(widget);
        addBtn->setObjectName("addBtn");
        addBtn->setMinimumSize(QSize(80, 30));
        addBtn->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(addBtn);

        already_add_lb = new QLabel(widget);
        already_add_lb->setObjectName("already_add_lb");
        already_add_lb->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(already_add_lb);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout->addWidget(widget);


        retranslateUi(applyFriendItem);

        QMetaObject::connectSlotsByName(applyFriendItem);
    } // setupUi

    void retranslateUi(QWidget *applyFriendItem)
    {
        applyFriendItem->setWindowTitle(QCoreApplication::translate("applyFriendItem", "Form", nullptr));
        icon_lb->setText(QCoreApplication::translate("applyFriendItem", "icon", nullptr));
        user_name_lb->setText(QCoreApplication::translate("applyFriendItem", "id", nullptr));
        user_chat_lb->setText(QCoreApplication::translate("applyFriendItem", "\347\224\263\350\257\267", nullptr));
        addBtn->setText(QCoreApplication::translate("applyFriendItem", "\346\267\273\345\212\240\345\210\260\345\245\275\345\217\213", nullptr));
        already_add_lb->setText(QCoreApplication::translate("applyFriendItem", "\345\267\262\346\267\273\345\212\240\345\210\260\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class applyFriendItem: public Ui_applyFriendItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYFRIENDITEM_H
