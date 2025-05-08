/********************************************************************************
** Form generated from reading UI file 'loadingdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGDLG_H
#define UI_LOADINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_loadingDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *loading_lb;

    void setupUi(QDialog *loadingDlg)
    {
        if (loadingDlg->objectName().isEmpty())
            loadingDlg->setObjectName("loadingDlg");
        loadingDlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(loadingDlg);
        verticalLayout->setObjectName("verticalLayout");
        loading_lb = new QLabel(loadingDlg);
        loading_lb->setObjectName("loading_lb");

        verticalLayout->addWidget(loading_lb);


        retranslateUi(loadingDlg);

        QMetaObject::connectSlotsByName(loadingDlg);
    } // setupUi

    void retranslateUi(QDialog *loadingDlg)
    {
        loadingDlg->setWindowTitle(QCoreApplication::translate("loadingDlg", "Dialog", nullptr));
        loading_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class loadingDlg: public Ui_loadingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGDLG_H
