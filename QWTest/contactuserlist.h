#ifndef CONTACTUSERLIST_H
#define CONTACTUSERLIST_H
#include <QListWidget>
#include <QEvent>
#include <QWheelEvent>
#include <QDebug>
#include <QScrollBar>
#include <memory>
#include "userdata.h"
class conUserItem;
class contactUserList:public QListWidget
{
    Q_OBJECT//带上信号和槽机制
public:
    contactUserList(QWidget *parent = nullptr);
    void showRedPoint(bool bshow);
protected:
    bool eventFilter(QObject *watched, QEvent *event)override;
private:
    void addContactUserList();
public slots:
    void slotItemClicked(QListWidgetItem *item);
    void slotAddAuthFirend(std::shared_ptr<AuthInfo>);
    void slotAuthRsp(std::shared_ptr<AuthRsp>);
signals:
    void sig_loading_contact_user();
    void sig_switch_apply_friend_page();
    void sig_switch_friend_info_page(std::shared_ptr<UserInfo> user_info);
private:
    bool _load_pending;
    conUserItem* _addFriendItem;
    QListWidgetItem* _groupitem;
};


#endif // CONTACTUSERLIST_H
