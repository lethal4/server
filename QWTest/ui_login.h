/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *headLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *userLabel;
    QLineEdit *userEdit;
    QLabel *waitwait;
    QHBoxLayout *horizontalLayout_4;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    clickedLabel *passwdvisit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *regButton;
    QSpacerItem *horizontalSpacer;
    clickedLabel *forgetLabel;
    QLabel *errTip;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(300, 500);
        Login->setMinimumSize(QSize(300, 450));
        Login->setMaximumSize(QSize(300, 500));
        Login->setStyleSheet(QString::fromUtf8("background: transparent;"));
        horizontalLayout_2 = new QHBoxLayout(Login);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        widget = new QWidget(Login);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        headLabel = new QLabel(widget);
        headLabel->setObjectName("headLabel");
        headLabel->setMinimumSize(QSize(200, 200));
        headLabel->setMaximumSize(QSize(200, 200));
        headLabel->setPixmap(QPixmap(QString::fromUtf8(":/icon.ico")));
        headLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        headLabel->setWordWrap(false);

        gridLayout->addWidget(headLabel, 1, 0, 1, 1);


        verticalLayout_2->addWidget(widget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        userLabel = new QLabel(Login);
        userLabel->setObjectName("userLabel");
        userLabel->setMinimumSize(QSize(0, 25));
        userLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(userLabel);

        userEdit = new QLineEdit(Login);
        userEdit->setObjectName("userEdit");
        userEdit->setMinimumSize(QSize(0, 40));
        userEdit->setMaximumSize(QSize(16777215, 40));
        userEdit->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(userEdit);

        waitwait = new QLabel(Login);
        waitwait->setObjectName("waitwait");
        waitwait->setMinimumSize(QSize(20, 20));
        waitwait->setMaximumSize(QSize(20, 20));

        horizontalLayout_3->addWidget(waitwait);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        passwordLabel = new QLabel(Login);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setMinimumSize(QSize(0, 25));
        passwordLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(Login);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setMinimumSize(QSize(0, 40));
        passwordEdit->setMaximumSize(QSize(16777215, 40));
        passwordEdit->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(passwordEdit);

        passwdvisit = new clickedLabel(Login);
        passwdvisit->setObjectName("passwdvisit");
        passwdvisit->setMinimumSize(QSize(20, 20));
        passwdvisit->setMaximumSize(QSize(20, 20));

        horizontalLayout_4->addWidget(passwdvisit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");
        loginButton->setMinimumSize(QSize(110, 45));
        loginButton->setMaximumSize(QSize(110, 45));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \n"
"    stop:0 #6A9FFF, stop:1 #4A78E1); /* \346\270\220\345\217\230\350\203\214\346\231\257 */\n"
"    border-radius: 12px; /* \345\234\206\350\247\222\346\225\210\346\236\234 */\n"
"    border: 2px solid #4A78E1; /* \350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 12px 24px; /* \350\260\203\346\225\264\345\206\205\350\276\271\350\267\235\357\274\214\347\241\256\344\277\235\346\226\207\345\255\227\346\230\276\347\244\272\345\256\214\346\225\264 */\n"
"    font-size: 16px; /* \350\260\203\346\225\264\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    color: white; /* \345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    text-align: center; /* \346\226\207\345\255\227\345\261\205\344\270\255 */\n"
"    transition: all 0.3s ease; /* \345\271\263\346\273\221\350\277\207\346\270\241\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0"
                        ", y1:0, x2:1, y2:0, \n"
"    stop:0 #4A78E1, stop:1 #6A9FFF); /* \346\202\254\345\201\234\346\227\266\347\232\204\346\270\220\345\217\230\350\203\214\346\231\257 */\n"
"    border: 2px solid #3A6C99; /* \346\202\254\345\201\234\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2); /* \346\202\254\345\201\234\346\227\266\347\232\204\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3A6C99; /* \346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    border: 2px solid #3A6C99; /* \346\214\211\344\270\213\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.2); /* \346\214\211\344\270\213\346\227\266\347\232\204\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none; /* \345\216\273\346\216\211\347\204\246\347\202\271\346"
                        "\227\266\347\232\204\345\244\226\350\275\256\345\273\223 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(loginButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        regButton = new QPushButton(Login);
        regButton->setObjectName("regButton");
        regButton->setMinimumSize(QSize(60, 30));
        regButton->setMaximumSize(QSize(60, 30));
        regButton->setStyleSheet(QString::fromUtf8("border: none; outline: none;"));

        horizontalLayout_5->addWidget(regButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        forgetLabel = new clickedLabel(Login);
        forgetLabel->setObjectName("forgetLabel");
        forgetLabel->setMinimumSize(QSize(0, 25));
        forgetLabel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(forgetLabel);


        verticalLayout_2->addLayout(horizontalLayout_5);

        errTip = new QLabel(Login);
        errTip->setObjectName("errTip");
        errTip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(errTip);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        headLabel->setText(QString());
        userLabel->setText(QCoreApplication::translate("Login", "\351\202\256\347\256\261\357\274\232", nullptr));
        waitwait->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwdvisit->setText(QString());
        loginButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        regButton->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\346\210\267", nullptr));
        forgetLabel->setText(QCoreApplication::translate("Login", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        errTip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
