#ifndef ADDUSERITEM_H
#define ADDUSERITEM_H

#include <QWidget>
#include "listitembase.h"
namespace Ui {
class addUserItem;
}

class addUserItem : public listItemBase
{
    Q_OBJECT

public:
    explicit addUserItem(QWidget *parent = nullptr);
    ~addUserItem();
    QSize sizeHint() const override{
        return QSize(250, 70);
    }

private:
    Ui::addUserItem *ui;
};

#endif // ADDUSERITEM_H
