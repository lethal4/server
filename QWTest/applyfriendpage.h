#ifndef APPLYFRIENDPAGE_H
#define APPLYFRIENDPAGE_H

#include <QWidget>
#include <QJsonArray>
#include <unordered_map>
#include <memory>
#include "userdata.h"
#include "applyfrienditem.h"
namespace Ui {
class applyFriendPage;
}

class applyFriendPage : public QWidget
{
    Q_OBJECT

public:
    explicit applyFriendPage(QWidget *parent = nullptr);
    ~applyFriendPage();
    void addNewApply(std::shared_ptr<AddFriendApply> apply);
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::applyFriendPage *ui;
    void loadApplyList();
    std::unordered_map<int,applyFriendItem *> _unauth_items;
public slots:
    void slotAuthRsp(std::shared_ptr<AuthRsp>);
signals:
    void sig_show_search(bool);
};

#endif // APPLYFRIENDPAGE_H
