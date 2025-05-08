#include "applyfriendpage.h"
#include "ui_applyfriendpage.h"
#include <QStyleOption>
#include <QPainter>
#include "tcpmgr.h"
#include "applyfriendlist.h"
#include <QRandomGenerator>
#include "usermgr.h"
#include "authenfriend.h"
applyFriendPage::applyFriendPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::applyFriendPage)
{
    ui->setupUi(this);

    connect(ui->apply_friend_list, &applyFriendList::sig_show_search, this,&applyFriendPage::sig_show_search);
    loadApplyList();
    connect(tcpMgr::getInstance().get(),&tcpMgr::sig_auth_rsp, this,&applyFriendPage::slotAuthRsp);
}

applyFriendPage::~applyFriendPage()
{
    delete ui;
}

void applyFriendPage::addNewApply(std::shared_ptr<AddFriendApply> apply)
{   std::vector<QString>  strs ={"hello world !",
                                 "nice to meet u",
                                 "New year，new life",
                                 "You have to love yourself",
                                 "My love is written in the wind ever since the whole world is you"};

    std::vector<QString> heads = {
        ":/res/head_1.jpg",
        ":/res/head_2.jpg",
        ":/res/head_3.jpg",
        ":/res/head_4.jpg",
        ":/res/head_5.jpg"
    };

    std::vector<QString> names = {
        "楚天齐", "李泽宇", "萧翰林", "沈浩然", "林承宇", "王思远", "唐景天", "赵云泽", "苏晨曦", "段云霄",
        "如梦凝霜", "林紫嫣", "宋婉儿", "沈雨晴", "陶晓筠", "许婧怡", "唐若彤", "沈书瑶", "柳依雪", "李瑾萱",
        "蒋承泽", "周子萱", "陈逸轩", "宋涵宇", "杨泽晗", "何紫晨", "王晓岚", "程佳琪", "陈昭萱", "赵云宁"
    };
    //模拟头像随机
    int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
    int head_i = randomValue % heads.size();
    auto* apply_item = new applyFriendItem();
    auto apply_info = std::make_shared<ApplyInfo>(apply->_from_uid,
                                                  apply->_name, apply->_desc,heads[head_i], apply->_name, 0, 0);
    apply_item->SetInfo( apply_info);
    QListWidgetItem* item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(apply_item->sizeHint());
    item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    ui->apply_friend_list->insertItem(0,item);
    ui->apply_friend_list->setItemWidget(item, apply_item);
    apply_item->ShowAddBtn(true);
    //收到审核好友信号
    connect(apply_item, &applyFriendItem::sig_auth_friend, [this](std::shared_ptr<ApplyInfo> apply_info) {
        auto* authFriend = new authenFriend(this);
        authFriend->setModal(true);
        authFriend->SetApplyInfo(apply_info);
        authFriend->show();
    });

}

void applyFriendPage::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void applyFriendPage::loadApplyList()
{
    std::vector<QString>  strs ={"hello world !",
                                 "nice to meet u",
                                 "New year，new life",
                                 "You have to love yourself",
                                 "My love is written in the wind ever since the whole world is you"};

    std::vector<QString> heads = {
        ":/res/head_1.jpg",
        ":/res/head_2.jpg",
        ":/res/head_3.jpg",
        ":/res/head_4.jpg",
        ":/res/head_5.jpg"
    };

    std::vector<QString> names = {
        "楚天齐", "李泽宇", "萧翰林", "沈浩然", "林承宇", "王思远", "唐景天", "赵云泽", "苏晨曦", "段云霄",
        "如梦凝霜", "林紫嫣", "宋婉儿", "沈雨晴", "陶晓筠", "许婧怡", "唐若彤", "沈书瑶", "柳依雪", "李瑾萱",
        "蒋承泽", "周子萱", "陈逸轩", "宋涵宇", "杨泽晗", "何紫晨", "王晓岚", "程佳琪", "陈昭萱", "赵云宁"
    };
    //添加好友申请
    auto apply_list = UserMgr::getInstance()->GetApplyList();
    for(auto &apply: apply_list){
        int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
        int head_i = randomValue % heads.size();
        auto* apply_item = new applyFriendItem();
        apply->SetIcon(heads[head_i]);
        apply_item->SetInfo(apply);
        QListWidgetItem* item = new QListWidgetItem;
        //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
        item->setSizeHint(apply_item->sizeHint());
        item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        ui->apply_friend_list->insertItem(0,item);
        ui->apply_friend_list->setItemWidget(item, apply_item);
        if(apply->_status){
            apply_item->ShowAddBtn(false);
        }else{
            apply_item->ShowAddBtn(true);
            auto uid = apply_item->GetUid();
            _unauth_items[uid] = apply_item;
        }

        //收到审核好友信号
        connect(apply_item, &applyFriendItem::sig_auth_friend, [this](std::shared_ptr<ApplyInfo> apply_info) {
            auto* authFriend = new authenFriend(this);
            authFriend->setModal(true);
            authFriend->SetApplyInfo(apply_info);
            authFriend->show();
        });
    }

    // 模拟假数据，创建QListWidgetItem，并设置自定义的widget
    for(int i = 0; i < 13; i++){
        int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
        int str_i = randomValue%strs.size();
        int head_i = randomValue%heads.size();
        int name_i = randomValue%names.size();

        auto *apply_item = new applyFriendItem();
        auto apply = std::make_shared<ApplyInfo>(0, names[name_i], strs[str_i],
                                                 heads[head_i], names[name_i], 0, 1);
        apply_item->SetInfo(apply);
        QListWidgetItem *item = new QListWidgetItem;
        //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
        item->setSizeHint(apply_item->sizeHint());
        item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        ui->apply_friend_list->addItem(item);
        ui->apply_friend_list->setItemWidget(item, apply_item);
        //收到审核好友信号
        connect(apply_item, &applyFriendItem::sig_auth_friend, [this](std::shared_ptr<ApplyInfo> apply_info){
            auto *authFriend =  new authenFriend(this);
            authFriend->setModal(true);
            authFriend->SetApplyInfo(apply_info);
            authFriend->show();
        });
    }

}

void applyFriendPage::slotAuthRsp(std::shared_ptr<AuthRsp> auth_rsp)
{
    auto uid = auth_rsp->_uid;
    auto find_iter = _unauth_items.find(uid);
    if (find_iter == _unauth_items.end()) {
        return;
    }

    find_iter->second->ShowAddBtn(false);

}
