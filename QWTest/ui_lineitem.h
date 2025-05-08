/********************************************************************************
** Form generated from reading UI file 'lineitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEITEM_H
#define UI_LINEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lineItem
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;

    void setupUi(QWidget *lineItem)
    {
        if (lineItem->objectName().isEmpty())
            lineItem->setObjectName("lineItem");
        lineItem->resize(400, 16);
        verticalLayout = new QVBoxLayout(lineItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(lineItem);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(lineItem);

        QMetaObject::connectSlotsByName(lineItem);
    } // setupUi

    void retranslateUi(QWidget *lineItem)
    {
        lineItem->setWindowTitle(QCoreApplication::translate("lineItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lineItem: public Ui_lineItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEITEM_H
