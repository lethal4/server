/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <applyfriendpage.h>
#include <chatpage.h>
#include <chatuserlist.h>
#include <clickbtn.h>
#include <contactuserlist.h>
#include <customedit.h>
#include <friendinfopage.h>
#include <searchlist.h>
#include <statewidget.h>

QT_BEGIN_NAMESPACE

class Ui_chatDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *sideBar;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *sideHeadLb;
    stateWidget *sideChatLb;
    stateWidget *sideContactLb;
    QSpacerItem *verticalSpacer;
    QWidget *chatUserWidth;
    QVBoxLayout *verticalLayout_2;
    QWidget *searchWidth;
    QHBoxLayout *horizontalLayout_2;
    customEdit *searchEdit;
    QSpacerItem *horizontalSpacer;
    clickBtn *addBtn;
    chatUserList *chatUserlist;
    searchList *searchLists;
    contactUserList *conUserList;
    QStackedWidget *stackedWidget;
    chatPage *chat_page;
    FriendInfoPage *friend_info_page;
    applyFriendPage *friend_apply_page;

    void setupUi(QDialog *chatDialog)
    {
        if (chatDialog->objectName().isEmpty())
            chatDialog->setObjectName("chatDialog");
        chatDialog->resize(1024, 800);
        chatDialog->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(chatDialog);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sideBar = new QWidget(chatDialog);
        sideBar->setObjectName("sideBar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sideBar->sizePolicy().hasHeightForWidth());
        sideBar->setSizePolicy(sizePolicy);
        sideBar->setMinimumSize(QSize(60, 0));
        sideBar->setMaximumSize(QSize(60, 16777215));
        verticalLayout = new QVBoxLayout(sideBar);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 30, 0, 0);
        widget = new QWidget(sideBar);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 150));
        widget->setMaximumSize(QSize(16777215, 150));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        sideHeadLb = new QLabel(widget);
        sideHeadLb->setObjectName("sideHeadLb");
        sideHeadLb->setMinimumSize(QSize(30, 30));
        sideHeadLb->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(sideHeadLb);

        sideChatLb = new stateWidget(widget);
        sideChatLb->setObjectName("sideChatLb");
        sideChatLb->setMinimumSize(QSize(30, 30));
        sideChatLb->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(sideChatLb);

        sideContactLb = new stateWidget(widget);
        sideContactLb->setObjectName("sideContactLb");
        sideContactLb->setMinimumSize(QSize(30, 30));
        sideContactLb->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(sideContactLb);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(sideBar);

        chatUserWidth = new QWidget(chatDialog);
        chatUserWidth->setObjectName("chatUserWidth");
        chatUserWidth->setMaximumSize(QSize(260, 16777215));
        verticalLayout_2 = new QVBoxLayout(chatUserWidth);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchWidth = new QWidget(chatUserWidth);
        searchWidth->setObjectName("searchWidth");
        searchWidth->setMinimumSize(QSize(0, 60));
        searchWidth->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(searchWidth);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        searchEdit = new customEdit(searchWidth);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout_2->addWidget(searchEdit);

        horizontalSpacer = new QSpacerItem(3, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addBtn = new clickBtn(searchWidth);
        addBtn->setObjectName("addBtn");
        addBtn->setMinimumSize(QSize(25, 25));
        addBtn->setMaximumSize(QSize(25, 25));

        horizontalLayout_2->addWidget(addBtn);


        verticalLayout_2->addWidget(searchWidth);

        chatUserlist = new chatUserList(chatUserWidth);
        chatUserlist->setObjectName("chatUserlist");

        verticalLayout_2->addWidget(chatUserlist);

        searchLists = new searchList(chatUserWidth);
        searchLists->setObjectName("searchLists");

        verticalLayout_2->addWidget(searchLists);

        conUserList = new contactUserList(chatUserWidth);
        conUserList->setObjectName("conUserList");

        verticalLayout_2->addWidget(conUserList);


        horizontalLayout->addWidget(chatUserWidth);

        stackedWidget = new QStackedWidget(chatDialog);
        stackedWidget->setObjectName("stackedWidget");
        chat_page = new chatPage();
        chat_page->setObjectName("chat_page");
        stackedWidget->addWidget(chat_page);
        friend_info_page = new FriendInfoPage();
        friend_info_page->setObjectName("friend_info_page");
        stackedWidget->addWidget(friend_info_page);
        friend_apply_page = new applyFriendPage();
        friend_apply_page->setObjectName("friend_apply_page");
        stackedWidget->addWidget(friend_apply_page);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(chatDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(chatDialog);
    } // setupUi

    void retranslateUi(QDialog *chatDialog)
    {
        chatDialog->setWindowTitle(QCoreApplication::translate("chatDialog", "Dialog", nullptr));
        sideHeadLb->setText(QString());
        addBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chatDialog: public Ui_chatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
