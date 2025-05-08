#include "lineitem.h"
#include "ui_lineitem.h"

lineItem::lineItem(QWidget *parent) :
    listItemBase(parent),
    ui(new Ui::lineItem)
{
    ui->setupUi(this);
    setItemType(ListItemType::LINE_ITEM);
}

lineItem::~lineItem()
{
    delete ui;
}

QSize lineItem::sizeHint() const
{
    return QSize(250,5); // 返回自定义的尺寸
}
