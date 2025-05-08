#ifndef CHATUSERWID_H
#define CHATUSERWID_H

#include "listitembase.h"
#include <QWidget>
#include "userdata.h"
namespace Ui {
class chatUserWid;
}

class chatUserWid : public listItemBase
{
    Q_OBJECT

public:
    explicit chatUserWid(QWidget *parent = nullptr);
    ~chatUserWid();

    QSize sizeHint() const override {
        return QSize(250, 70); // 返回自定义的尺寸
    }

    void SetInfo(std::shared_ptr<UserInfo> user_info);//设置名字等
    void SetInfo(std::shared_ptr<FriendInfo> friend_info);
    void ShowRedPoint(bool bshow);
    std::shared_ptr<UserInfo> GetUserInfo();
    void updateLastMsg(std::vector<std::shared_ptr<TextChatData>> msgs);
private:
    Ui::chatUserWid *ui;
    std::shared_ptr<UserInfo> _user_info;
};

#endif // CHATUSERWID_H
