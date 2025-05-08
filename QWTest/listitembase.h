#ifndef LISTITEMBASE_H
#define LISTITEMBASE_H
#include <QWidget>
#include "global.h"
class listItemBase :public QWidget//聊天头像等小控件
{
    Q_OBJECT
public:
    explicit listItemBase(QWidget * parent = nullptr);
    void setItemType(ListItemType itemType);
    ListItemType getItemType();

private:
    ListItemType _itemType;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

public slots:

signals:
};

#endif // LISTITEMBASE_H
