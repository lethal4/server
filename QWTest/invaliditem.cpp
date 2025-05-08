#include "invaliditem.h"

InvalidItem::InvalidItem(QWidget *parent) : listItemBase(parent)
{
    setItemType(ListItemType::INVALID_ITEM);
}

