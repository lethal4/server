/********************************************************************************
** Form generated from reading UI file 'adduseritem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERITEM_H
#define UI_ADDUSERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addUserItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *add_tip;
    QLabel *message_tip;
    QLabel *right_tip;

    void setupUi(QWidget *addUserItem)
    {
        if (addUserItem->objectName().isEmpty())
            addUserItem->setObjectName("addUserItem");
        addUserItem->resize(255, 75);
        addUserItem->setMinimumSize(QSize(255, 75));
        addUserItem->setMaximumSize(QSize(255, 75));
        horizontalLayout = new QHBoxLayout(addUserItem);
        horizontalLayout->setObjectName("horizontalLayout");
        add_tip = new QLabel(addUserItem);
        add_tip->setObjectName("add_tip");
        add_tip->setMinimumSize(QSize(40, 40));
        add_tip->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(add_tip);

        message_tip = new QLabel(addUserItem);
        message_tip->setObjectName("message_tip");

        horizontalLayout->addWidget(message_tip);

        right_tip = new QLabel(addUserItem);
        right_tip->setObjectName("right_tip");
        right_tip->setMinimumSize(QSize(40, 40));
        right_tip->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(right_tip);


        retranslateUi(addUserItem);

        QMetaObject::connectSlotsByName(addUserItem);
    } // setupUi

    void retranslateUi(QWidget *addUserItem)
    {
        addUserItem->setWindowTitle(QCoreApplication::translate("addUserItem", "Form", nullptr));
        add_tip->setText(QString());
        message_tip->setText(QCoreApplication::translate("addUserItem", "\346\237\245\346\211\276uid/\346\230\265\347\247\260", nullptr));
        right_tip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addUserItem: public Ui_addUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERITEM_H
