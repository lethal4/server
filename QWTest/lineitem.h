#ifndef LINEITEM_H
#define LINEITEM_H

#include <QWidget>
#include "listitembase.h"
namespace Ui {
class lineItem;
}

class lineItem : public listItemBase
{
    Q_OBJECT

public:
    explicit lineItem(QWidget *parent = nullptr);
    ~lineItem();
    QSize sizeHint() const override;
private:
    Ui::lineItem *ui;
};

#endif // LINEITEM_H
