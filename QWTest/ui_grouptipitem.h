/********************************************************************************
** Form generated from reading UI file 'grouptipitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPTIPITEM_H
#define UI_GROUPTIPITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupTipItem
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *groupTipItem)
    {
        if (groupTipItem->objectName().isEmpty())
            groupTipItem->setObjectName("groupTipItem");
        groupTipItem->resize(400, 30);
        groupTipItem->setMinimumSize(QSize(0, 30));
        groupTipItem->setMaximumSize(QSize(16777215, 30));
        verticalLayout = new QVBoxLayout(groupTipItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 0, 0, 0);
        label = new QLabel(groupTipItem);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        retranslateUi(groupTipItem);

        QMetaObject::connectSlotsByName(groupTipItem);
    } // setupUi

    void retranslateUi(QWidget *groupTipItem)
    {
        groupTipItem->setWindowTitle(QCoreApplication::translate("groupTipItem", "Form", nullptr));
        label->setText(QCoreApplication::translate("groupTipItem", "\346\226\260\347\232\204\346\234\213\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupTipItem: public Ui_groupTipItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPTIPITEM_H
