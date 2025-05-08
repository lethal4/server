#ifndef APPLYFRIENDITEM_H
#define APPLYFRIENDITEM_H

#include <QWidget>
#include "listitembase.h"
#include "userdata.h"
#include <memory>
namespace Ui {
class applyFriendItem;
}

class applyFriendItem : public listItemBase
{
    Q_OBJECT

public:
    explicit applyFriendItem(QWidget *parent = nullptr);
    ~applyFriendItem();
    void SetInfo(std::shared_ptr<ApplyInfo> apply_info);
    void ShowAddBtn(bool bshow);
    QSize sizeHint() const override {
        return QSize(270, 80); // 返回自定义的尺寸
    }
    int GetUid();
private:
    Ui::applyFriendItem *ui;
    std::shared_ptr<ApplyInfo> _apply_info;
    bool _added;
signals:
    void sig_auth_friend(std::shared_ptr<ApplyInfo> apply_info);
};

#endif // APPLYFRIENDITEM_H
