/********************************************************************************
** Form generated from reading UI file 'applyfriendpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYFRIENDPAGE_H
#define UI_APPLYFRIENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <applyfriendlist.h>

QT_BEGIN_NAMESPACE

class Ui_applyFriendPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *friend_apply_wid;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *friend_apply_lb;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    applyFriendList *apply_friend_list;

    void setupUi(QWidget *applyFriendPage)
    {
        if (applyFriendPage->objectName().isEmpty())
            applyFriendPage->setObjectName("applyFriendPage");
        applyFriendPage->resize(786, 443);
        verticalLayout = new QVBoxLayout(applyFriendPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        friend_apply_wid = new QWidget(applyFriendPage);
        friend_apply_wid->setObjectName("friend_apply_wid");
        horizontalLayout = new QHBoxLayout(friend_apply_wid);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        friend_apply_lb = new QLabel(friend_apply_wid);
        friend_apply_lb->setObjectName("friend_apply_lb");
        friend_apply_lb->setMinimumSize(QSize(70, 45));
        friend_apply_lb->setMaximumSize(QSize(70, 45));

        horizontalLayout->addWidget(friend_apply_lb);

        horizontalSpacer = new QSpacerItem(728, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(friend_apply_wid);

        widget_2 = new QWidget(applyFriendPage);
        widget_2->setObjectName("widget_2");
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        apply_friend_list = new applyFriendList(widget_2);
        apply_friend_list->setObjectName("apply_friend_list");

        verticalLayout_2->addWidget(apply_friend_list);


        verticalLayout->addWidget(widget_2);


        retranslateUi(applyFriendPage);

        QMetaObject::connectSlotsByName(applyFriendPage);
    } // setupUi

    void retranslateUi(QWidget *applyFriendPage)
    {
        applyFriendPage->setWindowTitle(QCoreApplication::translate("applyFriendPage", "Form", nullptr));
        friend_apply_lb->setText(QCoreApplication::translate("applyFriendPage", "\346\226\260\347\232\204\346\234\213\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class applyFriendPage: public Ui_applyFriendPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYFRIENDPAGE_H
