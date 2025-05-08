#include "grouptipitem.h"
#include "ui_grouptipitem.h"

groupTipItem::groupTipItem(QWidget *parent):listItemBase (parent),_tip(""), ui(new Ui::groupTipItem)
{
    ui->setupUi(this);
    setItemType(ListItemType::GROUP_TIP_ITEM);
}

groupTipItem::~groupTipItem()
{
    delete ui;
}
QSize groupTipItem::sizeHint() const
{
    return QSize(250, 25); // 返回自定义的尺寸
}

void groupTipItem::SetGroupTip(QString str)
{
    ui->label->setText(str);
}


