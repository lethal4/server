#ifndef CONUSERITEM_H
#define CONUSERITEM_H

#include <QWidget>
#include "listitembase.h"
#include "userdata.h"
namespace Ui {
class conUserItem;
}

class conUserItem : public listItemBase
{
    Q_OBJECT

public:
    explicit conUserItem(QWidget *parent = nullptr);

    ~conUserItem();
    QSize sizeHint() const override;
    void setInfo(std::shared_ptr<AuthInfo> auth_info);
    void setInfo(std::shared_ptr<AuthRsp> auth_rsp);
    void setInfo(int uid, QString name, QString icon);
    void showRedPoint(bool show);

    std::shared_ptr<UserInfo> GetInfo();
private:
    Ui::conUserItem *ui;
    std::shared_ptr<UserInfo> _info;
};

#endif // CONUSERITEM_H
