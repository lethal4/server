/********************************************************************************
** Form generated from reading UI file 'findfaildlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFAILDLG_H
#define UI_FINDFAILDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickbtn.h>

QT_BEGIN_NAMESPACE

class Ui_findFailDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *fail_tip;
    QLabel *fail_tip2;
    QWidget *widget;
    clickBtn *fail_sure_btn;

    void setupUi(QDialog *findFailDlg)
    {
        if (findFailDlg->objectName().isEmpty())
            findFailDlg->setObjectName("findFailDlg");
        findFailDlg->resize(255, 155);
        findFailDlg->setMinimumSize(QSize(255, 155));
        findFailDlg->setMaximumSize(QSize(255, 155));
        verticalLayout = new QVBoxLayout(findFailDlg);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        fail_tip = new QLabel(findFailDlg);
        fail_tip->setObjectName("fail_tip");
        fail_tip->setMinimumSize(QSize(0, 30));
        fail_tip->setMaximumSize(QSize(16777215, 30));
        fail_tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(fail_tip);

        fail_tip2 = new QLabel(findFailDlg);
        fail_tip2->setObjectName("fail_tip2");
        fail_tip2->setMinimumSize(QSize(0, 30));
        fail_tip2->setMaximumSize(QSize(16777215, 30));
        fail_tip2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(fail_tip2);

        widget = new QWidget(findFailDlg);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        fail_sure_btn = new clickBtn(widget);
        fail_sure_btn->setObjectName("fail_sure_btn");
        fail_sure_btn->setGeometry(QRect(70, 10, 100, 30));
        fail_sure_btn->setMinimumSize(QSize(100, 30));
        fail_sure_btn->setMaximumSize(QSize(100, 30));

        verticalLayout->addWidget(widget);


        retranslateUi(findFailDlg);

        QMetaObject::connectSlotsByName(findFailDlg);
    } // setupUi

    void retranslateUi(QDialog *findFailDlg)
    {
        findFailDlg->setWindowTitle(QCoreApplication::translate("findFailDlg", "Dialog", nullptr));
        fail_tip->setText(QCoreApplication::translate("findFailDlg", "\346\227\240\346\263\225\346\211\276\345\210\260\350\257\245\347\224\250\346\210\267", nullptr));
        fail_tip2->setText(QCoreApplication::translate("findFailDlg", "\350\257\267\346\243\200\346\237\245\346\230\257\345\220\246\345\255\230\345\234\250\350\257\245\347\224\250\346\210\267", nullptr));
        fail_sure_btn->setText(QCoreApplication::translate("findFailDlg", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class findFailDlg: public Ui_findFailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFAILDLG_H
