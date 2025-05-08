#include "adduseritem.h"
#include "ui_adduseritem.h"

addUserItem::addUserItem(QWidget *parent) : listItemBase(parent),
    ui(new Ui::addUserItem)
{
    ui->setupUi(this);
    setItemType(ListItemType::ADD_USER_TIP_ITEM);
}

addUserItem::~addUserItem()
{
    delete ui;
}
