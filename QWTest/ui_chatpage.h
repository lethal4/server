/********************************************************************************
** Form generated from reading UI file 'chatpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <chatview.h>
#include <clickbtn.h>
#include <clickedlabel.h>
#include <messagetextedit.h>

QT_BEGIN_NAMESPACE

class Ui_chatPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *chatDataWidth;
    QVBoxLayout *verticalLayout_6;
    QWidget *titleWidth;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *titleLb;
    chatView *chatDataList;
    QWidget *toolWidth;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_8;
    clickedLabel *emoLb;
    QSpacerItem *horizontalSpacer_9;
    clickedLabel *fileLb;
    QSpacerItem *horizontalSpacer_10;
    messageTextEdit *chatEdit;
    QWidget *sendWid;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_11;
    clickBtn *receiveBtn;
    QSpacerItem *horizontalSpacer_12;
    clickBtn *sendBtn;
    QSpacerItem *horizontalSpacer_13;

    void setupUi(QWidget *chatPage)
    {
        if (chatPage->objectName().isEmpty())
            chatPage->setObjectName("chatPage");
        chatPage->resize(557, 1020);
        chatPage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(chatPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chatDataWidth = new QWidget(chatPage);
        chatDataWidth->setObjectName("chatDataWidth");
        chatDataWidth->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_6 = new QVBoxLayout(chatDataWidth);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        titleWidth = new QWidget(chatDataWidth);
        titleWidth->setObjectName("titleWidth");
        titleWidth->setMinimumSize(QSize(0, 60));
        titleWidth->setMaximumSize(QSize(16777215, 60));
        titleWidth->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_7 = new QVBoxLayout(titleWidth);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(-1, 2, 2, 2);
        widget = new QWidget(titleWidth);
        widget->setObjectName("widget");
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(2, 2, 2, 2);
        titleLb = new QLabel(widget);
        titleLb->setObjectName("titleLb");

        horizontalLayout_6->addWidget(titleLb);


        verticalLayout_7->addWidget(widget);


        verticalLayout_6->addWidget(titleWidth);

        chatDataList = new chatView(chatDataWidth);
        chatDataList->setObjectName("chatDataList");
        chatDataList->setMinimumSize(QSize(0, 580));
        chatDataList->setMaximumSize(QSize(16777215, 580));
        chatDataList->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(chatDataList);

        toolWidth = new QWidget(chatDataWidth);
        toolWidth->setObjectName("toolWidth");
        toolWidth->setMinimumSize(QSize(0, 45));
        toolWidth->setMaximumSize(QSize(16777215, 45));
        toolWidth->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_7 = new QHBoxLayout(toolWidth);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer_8 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        emoLb = new clickedLabel(toolWidth);
        emoLb->setObjectName("emoLb");
        emoLb->setMinimumSize(QSize(30, 30));
        emoLb->setMaximumSize(QSize(30, 30));

        horizontalLayout_7->addWidget(emoLb);

        horizontalSpacer_9 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        fileLb = new clickedLabel(toolWidth);
        fileLb->setObjectName("fileLb");
        fileLb->setMinimumSize(QSize(30, 30));
        fileLb->setMaximumSize(QSize(30, 30));

        horizontalLayout_7->addWidget(fileLb);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);


        verticalLayout_6->addWidget(toolWidth);

        chatEdit = new messageTextEdit(chatDataWidth);
        chatEdit->setObjectName("chatEdit");
        chatEdit->setMinimumSize(QSize(0, 275));
        chatEdit->setMaximumSize(QSize(16777215, 275));
        chatEdit->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(chatEdit);

        sendWid = new QWidget(chatDataWidth);
        sendWid->setObjectName("sendWid");
        sendWid->setMinimumSize(QSize(0, 60));
        sendWid->setMaximumSize(QSize(16777215, 60));
        sendWid->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_8 = new QHBoxLayout(sendWid);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(439, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        receiveBtn = new clickBtn(sendWid);
        receiveBtn->setObjectName("receiveBtn");
        receiveBtn->setMinimumSize(QSize(100, 30));
        receiveBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout_8->addWidget(receiveBtn);

        horizontalSpacer_12 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);

        sendBtn = new clickBtn(sendWid);
        sendBtn->setObjectName("sendBtn");
        sendBtn->setMinimumSize(QSize(100, 30));
        sendBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout_8->addWidget(sendBtn);

        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);


        verticalLayout_6->addWidget(sendWid);


        verticalLayout->addWidget(chatDataWidth);


        retranslateUi(chatPage);

        QMetaObject::connectSlotsByName(chatPage);
    } // setupUi

    void retranslateUi(QWidget *chatPage)
    {
        chatPage->setWindowTitle(QCoreApplication::translate("chatPage", "Form", nullptr));
        titleLb->setText(QCoreApplication::translate("chatPage", "\345\244\247\347\261\263\347\262\245\346\230\257\345\245\275\347\262\245", nullptr));
        emoLb->setText(QString());
        fileLb->setText(QString());
        receiveBtn->setText(QString());
        sendBtn->setText(QCoreApplication::translate("chatPage", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatPage: public Ui_chatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
