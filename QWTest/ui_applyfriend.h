/********************************************************************************
** Form generated from reading UI file 'applyfriend.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYFRIEND_H
#define UI_APPLYFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickbtn.h>
#include <clickedoncelabel.h>
#include "customEdit.h"

QT_BEGIN_NAMESPACE

class Ui_applyFriend
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollcontent;
    QVBoxLayout *verticalLayout_6;
    QLabel *apply_lb;
    QWidget *apply_wid;
    QVBoxLayout *verticalLayout_2;
    QFrame *h_line;
    QLabel *label;
    customEdit *name_ed;
    QLabel *label_2;
    customEdit *back_ed;
    QLabel *label_3;
    QWidget *lb_group_wid;
    QVBoxLayout *verticalLayout_4;
    QWidget *gridWidget;
    customEdit *lb_ed;
    QWidget *input_tip_wid;
    QVBoxLayout *verticalLayout_5;
    clickedOnceLabel *tip_lb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *lb_list;
    QWidget *more_lb_wid;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    clickedOnceLabel *more_lb;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QWidget *apply_sure_wid;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    clickBtn *sure_btn;
    QSpacerItem *horizontalSpacer_3;
    clickBtn *cancel_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *applyFriend)
    {
        if (applyFriend->objectName().isEmpty())
            applyFriend->setObjectName("applyFriend");
        applyFriend->resize(361, 621);
        applyFriend->setMinimumSize(QSize(361, 621));
        applyFriend->setMaximumSize(QSize(361, 621));
        verticalLayout = new QVBoxLayout(applyFriend);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(applyFriend);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(0, 500));
        scrollArea->setWidgetResizable(true);
        scrollcontent = new QWidget();
        scrollcontent->setObjectName("scrollcontent");
        scrollcontent->setGeometry(QRect(0, 0, 359, 498));
        verticalLayout_6 = new QVBoxLayout(scrollcontent);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, -1, 0, -1);
        apply_lb = new QLabel(scrollcontent);
        apply_lb->setObjectName("apply_lb");
        apply_lb->setMinimumSize(QSize(0, 25));
        apply_lb->setMaximumSize(QSize(16777215, 25));
        apply_lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(apply_lb);

        apply_wid = new QWidget(scrollcontent);
        apply_wid->setObjectName("apply_wid");
        verticalLayout_2 = new QVBoxLayout(apply_wid);
        verticalLayout_2->setObjectName("verticalLayout_2");
        h_line = new QFrame(apply_wid);
        h_line->setObjectName("h_line");
        h_line->setFrameShape(QFrame::Shape::HLine);
        h_line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(h_line);

        label = new QLabel(apply_wid);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 25));
        label->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label);

        name_ed = new customEdit(apply_wid);
        name_ed->setObjectName("name_ed");
        name_ed->setMinimumSize(QSize(0, 35));
        name_ed->setMaximumSize(QSize(16777215, 35));

        verticalLayout_2->addWidget(name_ed);

        label_2 = new QLabel(apply_wid);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_2);

        back_ed = new customEdit(apply_wid);
        back_ed->setObjectName("back_ed");
        back_ed->setMinimumSize(QSize(0, 35));
        back_ed->setMaximumSize(QSize(16777215, 35));

        verticalLayout_2->addWidget(back_ed);

        label_3 = new QLabel(apply_wid);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 25));
        label_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_3);

        lb_group_wid = new QWidget(apply_wid);
        lb_group_wid->setObjectName("lb_group_wid");
        lb_group_wid->setMinimumSize(QSize(0, 50));
        verticalLayout_4 = new QVBoxLayout(lb_group_wid);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridWidget = new QWidget(lb_group_wid);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setMinimumSize(QSize(0, 40));
        gridWidget->setMaximumSize(QSize(16777215, 40));
        lb_ed = new customEdit(gridWidget);
        lb_ed->setObjectName("lb_ed");
        lb_ed->setGeometry(QRect(2, 2, 108, 35));
        lb_ed->setMinimumSize(QSize(0, 0));
        lb_ed->setMaximumSize(QSize(16777215, 35));

        verticalLayout_4->addWidget(gridWidget);

        input_tip_wid = new QWidget(lb_group_wid);
        input_tip_wid->setObjectName("input_tip_wid");
        input_tip_wid->setMinimumSize(QSize(0, 35));
        verticalLayout_5 = new QVBoxLayout(input_tip_wid);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tip_lb = new clickedOnceLabel(input_tip_wid);
        tip_lb->setObjectName("tip_lb");
        tip_lb->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_5->addWidget(tip_lb);


        verticalLayout_4->addWidget(input_tip_wid);


        verticalLayout_2->addWidget(lb_group_wid);

        widget = new QWidget(apply_wid);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lb_list = new QWidget(widget);
        lb_list->setObjectName("lb_list");
        lb_list->setMinimumSize(QSize(287, 50));
        lb_list->setMaximumSize(QSize(287, 16777215));

        horizontalLayout->addWidget(lb_list);

        more_lb_wid = new QWidget(widget);
        more_lb_wid->setObjectName("more_lb_wid");
        more_lb_wid->setMinimumSize(QSize(30, 0));
        more_lb_wid->setMaximumSize(QSize(30, 16777215));
        verticalLayout_3 = new QVBoxLayout(more_lb_wid);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        more_lb = new clickedOnceLabel(more_lb_wid);
        more_lb->setObjectName("more_lb");
        more_lb->setMinimumSize(QSize(25, 25));
        more_lb->setMaximumSize(QSize(25, 25));

        verticalLayout_3->addWidget(more_lb);

        verticalSpacer_4 = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);


        horizontalLayout->addWidget(more_lb_wid);


        verticalLayout_2->addWidget(widget);


        verticalLayout_6->addWidget(apply_wid);

        scrollArea->setWidget(scrollcontent);

        verticalLayout->addWidget(scrollArea);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        apply_sure_wid = new QWidget(applyFriend);
        apply_sure_wid->setObjectName("apply_sure_wid");
        apply_sure_wid->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(apply_sure_wid);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(39, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        sure_btn = new clickBtn(apply_sure_wid);
        sure_btn->setObjectName("sure_btn");
        sure_btn->setMinimumSize(QSize(100, 30));
        sure_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(sure_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        cancel_btn = new clickBtn(apply_sure_wid);
        cancel_btn->setObjectName("cancel_btn");
        cancel_btn->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(cancel_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(apply_sure_wid);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(applyFriend);

        QMetaObject::connectSlotsByName(applyFriend);
    } // setupUi

    void retranslateUi(QDialog *applyFriend)
    {
        applyFriend->setWindowTitle(QCoreApplication::translate("applyFriend", "Dialog", nullptr));
        apply_lb->setText(QCoreApplication::translate("applyFriend", "\347\224\263\350\257\267\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        label->setText(QCoreApplication::translate("applyFriend", "\345\217\221\351\200\201\346\267\273\345\212\240\346\234\213\345\217\213\347\224\263\350\257\267", nullptr));
        label_2->setText(QCoreApplication::translate("applyFriend", "\345\244\207\346\263\250\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("applyFriend", "\346\240\207\347\255\276", nullptr));
        tip_lb->setText(QCoreApplication::translate("applyFriend", "TextLabel", nullptr));
        more_lb->setText(QString());
        sure_btn->setText(QCoreApplication::translate("applyFriend", "\347\241\256\350\256\244", nullptr));
        cancel_btn->setText(QCoreApplication::translate("applyFriend", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class applyFriend: public Ui_applyFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYFRIEND_H
