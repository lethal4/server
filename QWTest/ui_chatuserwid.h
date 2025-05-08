/********************************************************************************
** Form generated from reading UI file 'chatuserwid.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATUSERWID_H
#define UI_CHATUSERWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatUserWid
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *icon_wid;
    QLabel *icon_lb;
    QLabel *red_point;
    QWidget *user_info_wid;
    QVBoxLayout *verticalLayout;
    QLabel *user_name_lb;
    QLabel *user_chat_lb;
    QWidget *time_wid;
    QHBoxLayout *horizontalLayout_3;
    QLabel *time_lb;

    void setupUi(QWidget *chatUserWid)
    {
        if (chatUserWid->objectName().isEmpty())
            chatUserWid->setObjectName("chatUserWid");
        chatUserWid->resize(400, 65);
        chatUserWid->setMinimumSize(QSize(0, 65));
        chatUserWid->setMaximumSize(QSize(16777215, 65));
        horizontalLayout = new QHBoxLayout(chatUserWid);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(6, 2, 6, 2);
        icon_wid = new QWidget(chatUserWid);
        icon_wid->setObjectName("icon_wid");
        icon_wid->setMinimumSize(QSize(50, 50));
        icon_wid->setMaximumSize(QSize(50, 50));
        icon_lb = new QLabel(icon_wid);
        icon_lb->setObjectName("icon_lb");
        icon_lb->setGeometry(QRect(0, 2, 45, 45));
        icon_lb->setMinimumSize(QSize(45, 45));
        icon_lb->setMaximumSize(QSize(45, 45));
        icon_lb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        red_point = new QLabel(icon_wid);
        red_point->setObjectName("red_point");
        red_point->setGeometry(QRect(27, 0, 30, 30));
        red_point->setMinimumSize(QSize(30, 30));
        red_point->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(icon_wid);

        user_info_wid = new QWidget(chatUserWid);
        user_info_wid->setObjectName("user_info_wid");
        verticalLayout = new QVBoxLayout(user_info_wid);
        verticalLayout->setObjectName("verticalLayout");
        user_name_lb = new QLabel(user_info_wid);
        user_name_lb->setObjectName("user_name_lb");

        verticalLayout->addWidget(user_name_lb);

        user_chat_lb = new QLabel(user_info_wid);
        user_chat_lb->setObjectName("user_chat_lb");

        verticalLayout->addWidget(user_chat_lb);


        horizontalLayout->addWidget(user_info_wid);

        time_wid = new QWidget(chatUserWid);
        time_wid->setObjectName("time_wid");
        time_wid->setMinimumSize(QSize(50, 50));
        time_wid->setMaximumSize(QSize(50, 50));
        horizontalLayout_3 = new QHBoxLayout(time_wid);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        time_lb = new QLabel(time_wid);
        time_lb->setObjectName("time_lb");
        time_lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(time_lb);


        horizontalLayout->addWidget(time_wid);


        retranslateUi(chatUserWid);

        QMetaObject::connectSlotsByName(chatUserWid);
    } // setupUi

    void retranslateUi(QWidget *chatUserWid)
    {
        chatUserWid->setWindowTitle(QCoreApplication::translate("chatUserWid", "Form", nullptr));
        icon_lb->setText(QCoreApplication::translate("chatUserWid", "\345\233\276\345\203\217", nullptr));
        red_point->setText(QString());
        user_name_lb->setText(QCoreApplication::translate("chatUserWid", "\345\244\247\347\261\263\347\262\245hh", nullptr));
        user_chat_lb->setText(QCoreApplication::translate("chatUserWid", "\344\275\240\347\214\234\346\210\221\345\217\221\344\272\206\344\273\200\344\271\210", nullptr));
        time_lb->setText(QCoreApplication::translate("chatUserWid", "13:14", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatUserWid: public Ui_chatUserWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATUSERWID_H
