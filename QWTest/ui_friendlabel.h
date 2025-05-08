/********************************************************************************
** Form generated from reading UI file 'friendlabel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLABEL_H
#define UI_FRIENDLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>

QT_BEGIN_NAMESPACE

class Ui_friendLabel
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *tip_lb;
    QWidget *close_wid;
    QHBoxLayout *horizontalLayout_2;
    clickedLabel *close_lb;

    void setupUi(QWidget *friendLabel)
    {
        if (friendLabel->objectName().isEmpty())
            friendLabel->setObjectName("friendLabel");
        friendLabel->resize(400, 43);
        friendLabel->setMinimumSize(QSize(0, 43));
        friendLabel->setMaximumSize(QSize(16777215, 43));
        friendLabel->setStyleSheet(QString::fromUtf8("#FriendLabel {\n"
"	background: #daf6e7;\n"
"    color: #48bf56;\n"
"    border-radius: 10px;\n"
"} "));
        horizontalLayout = new QHBoxLayout(friendLabel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tip_lb = new QLabel(friendLabel);
        tip_lb->setObjectName("tip_lb");
        tip_lb->setMinimumSize(QSize(0, 20));
        tip_lb->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(tip_lb);

        close_wid = new QWidget(friendLabel);
        close_wid->setObjectName("close_wid");
        close_wid->setMinimumSize(QSize(25, 25));
        close_wid->setMaximumSize(QSize(25, 25));
        horizontalLayout_2 = new QHBoxLayout(close_wid);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        close_lb = new clickedLabel(close_wid);
        close_lb->setObjectName("close_lb");
        close_lb->setMinimumSize(QSize(15, 15));
        close_lb->setMaximumSize(QSize(15, 15));
        close_lb->setStyleSheet(QString::fromUtf8("border-image: url(:/res/tipclose.png);"));

        horizontalLayout_2->addWidget(close_lb);


        horizontalLayout->addWidget(close_wid);


        retranslateUi(friendLabel);

        QMetaObject::connectSlotsByName(friendLabel);
    } // setupUi

    void retranslateUi(QWidget *friendLabel)
    {
        friendLabel->setWindowTitle(QCoreApplication::translate("friendLabel", "Form", nullptr));
        tip_lb->setText(QCoreApplication::translate("friendLabel", "TextLabel", nullptr));
        close_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class friendLabel: public Ui_friendLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLABEL_H
