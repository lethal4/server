#ifndef GROUPTIPITEM_H
#define GROUPTIPITEM_H

#include <QWidget>
#include "listitembase.h"
namespace Ui {
class groupTipItem;
}

class groupTipItem :  public listItemBase
{
    Q_OBJECT

public:
    explicit groupTipItem(QWidget *parent = nullptr);

    ~groupTipItem();
    QSize sizeHint() const override;
    void SetGroupTip(QString str);
private:
    QString _tip;
    Ui::groupTipItem *ui;
};

#endif // GROUPTIPITEM_H
