/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>
#include "timebtn.h"

QT_BEGIN_NAMESPACE

class Ui_registerDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *errTip;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *userEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    clickedLabel *passwordVisble;
    QHBoxLayout *horizontalLayout_4;
    QLabel *passwordTwoLabel;
    QLineEdit *passwordTwoEdit;
    clickedLabel *passwordTwoVisble;
    QHBoxLayout *horizontalLayout_6;
    QLabel *varifyLabel;
    QLineEdit *varifyEdit;
    timeBtn *getCode;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *sureButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *tipLabelOne;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *returnButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *registerDialog)
    {
        if (registerDialog->objectName().isEmpty())
            registerDialog->setObjectName("registerDialog");
        registerDialog->resize(300, 500);
        registerDialog->setMinimumSize(QSize(300, 500));
        registerDialog->setMaximumSize(QSize(300, 500));
        registerDialog->setStyleSheet(QString::fromUtf8("background: transparent;"));
        verticalLayout_2 = new QVBoxLayout(registerDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(registerDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        errTip = new QLabel(page);
        errTip->setObjectName("errTip");
        errTip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(errTip);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        userLabel = new QLabel(page);
        userLabel->setObjectName("userLabel");
        userLabel->setMinimumSize(QSize(0, 40));
        userLabel->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(userLabel);

        userEdit = new QLineEdit(page);
        userEdit->setObjectName("userEdit");
        userEdit->setMinimumSize(QSize(0, 30));
        userEdit->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(userEdit);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        emailLabel = new QLabel(page);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setMinimumSize(QSize(0, 40));
        emailLabel->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_2->addWidget(emailLabel);

        emailEdit = new QLineEdit(page);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setMinimumSize(QSize(0, 30));
        emailEdit->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(emailEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        passwordLabel = new QLabel(page);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setMinimumSize(QSize(0, 40));
        passwordLabel->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_3->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(page);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setMinimumSize(QSize(0, 30));
        passwordEdit->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(passwordEdit);

        passwordVisble = new clickedLabel(page);
        passwordVisble->setObjectName("passwordVisble");
        passwordVisble->setMinimumSize(QSize(20, 20));
        passwordVisble->setMaximumSize(QSize(20, 20));

        horizontalLayout_3->addWidget(passwordVisble);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        passwordTwoLabel = new QLabel(page);
        passwordTwoLabel->setObjectName("passwordTwoLabel");
        passwordTwoLabel->setMinimumSize(QSize(0, 40));
        passwordTwoLabel->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_4->addWidget(passwordTwoLabel);

        passwordTwoEdit = new QLineEdit(page);
        passwordTwoEdit->setObjectName("passwordTwoEdit");
        passwordTwoEdit->setMinimumSize(QSize(0, 30));
        passwordTwoEdit->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(passwordTwoEdit);

        passwordTwoVisble = new clickedLabel(page);
        passwordTwoVisble->setObjectName("passwordTwoVisble");
        passwordTwoVisble->setMinimumSize(QSize(20, 20));
        passwordTwoVisble->setMaximumSize(QSize(20, 20));

        horizontalLayout_4->addWidget(passwordTwoVisble);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        varifyLabel = new QLabel(page);
        varifyLabel->setObjectName("varifyLabel");
        varifyLabel->setMinimumSize(QSize(0, 40));
        varifyLabel->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_6->addWidget(varifyLabel);

        varifyEdit = new QLineEdit(page);
        varifyEdit->setObjectName("varifyEdit");
        varifyEdit->setMinimumSize(QSize(0, 30));
        varifyEdit->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_6->addWidget(varifyEdit);

        getCode = new timeBtn(page);
        getCode->setObjectName("getCode");
        getCode->setMinimumSize(QSize(0, 30));
        getCode->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_6->addWidget(getCode);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        sureButton = new QPushButton(page);
        sureButton->setObjectName("sureButton");
        sureButton->setMinimumSize(QSize(0, 25));
        sureButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(sureButton);

        cancelButton = new QPushButton(page);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setMinimumSize(QSize(0, 25));
        cancelButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(cancelButton);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        tipLabelOne = new QLabel(page_2);
        tipLabelOne->setObjectName("tipLabelOne");
        tipLabelOne->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(tipLabelOne);

        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        widget = new QWidget(page_2);
        widget->setObjectName("widget");
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        returnButton = new QPushButton(widget);
        returnButton->setObjectName("returnButton");
        returnButton->setMinimumSize(QSize(0, 25));
        returnButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(returnButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(registerDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(registerDialog);
    } // setupUi

    void retranslateUi(QDialog *registerDialog)
    {
        registerDialog->setWindowTitle(QCoreApplication::translate("registerDialog", "Dialog", nullptr));
        errTip->setText(QCoreApplication::translate("registerDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        userLabel->setText(QCoreApplication::translate("registerDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        emailLabel->setText(QCoreApplication::translate("registerDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        passwordLabel->setText(QCoreApplication::translate("registerDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwordVisble->setText(QString());
        passwordTwoLabel->setText(QCoreApplication::translate("registerDialog", "\347\241\256\350\256\244\357\274\232", nullptr));
        passwordTwoVisble->setText(QString());
        varifyLabel->setText(QCoreApplication::translate("registerDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        getCode->setText(QCoreApplication::translate("registerDialog", "\350\216\267\345\217\226", nullptr));
        sureButton->setText(QCoreApplication::translate("registerDialog", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("registerDialog", "\345\217\226\346\266\210", nullptr));
        tipLabelOne->setText(QCoreApplication::translate("registerDialog", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\2143\347\247\222\345\220\216\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("registerDialog", "\347\202\271\345\207\273\350\277\224\345\233\236\346\214\211\351\222\256\345\277\253\351\200\237\350\277\224\345\233\236", nullptr));
        returnButton->setText(QCoreApplication::translate("registerDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerDialog: public Ui_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
