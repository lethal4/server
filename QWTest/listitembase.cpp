#include "listitembase.h"
#include <QStyleOption>
#include <QPainter>
listItemBase::listItemBase(QWidget *parent) : QWidget (parent)
{

}

void listItemBase::setItemType(ListItemType itemType)
{
    _itemType = itemType;
}

ListItemType listItemBase::getItemType()
{
    return _itemType;
}

void listItemBase::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
