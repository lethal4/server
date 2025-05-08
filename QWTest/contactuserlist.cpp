#include "contactuserlist.h"
#include "tcpmgr.h"
#include "listItemBase.h"
#include "groupTipItem.h"
#include "conUserItem.h"
#include <QRandomGenerator>
#include "usermgr.h"
#include "userdata.h"
#include <QTimer>
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
contactUserList::contactUserList(QWidget *parent):QListWidget(parent)
{
    Q_UNUSED(parent);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//关闭水平
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//关闭垂直
    this->viewport()->installEventFilter(this);//安装事件过滤器

    addContactUserList();//模拟加载

    connect(this, &QListWidget::itemClicked, this, &contactUserList::slotItemClicked);
    connect(tcpMgr::getInstance().get(),&tcpMgr::sig_add_auth_friend,this, &contactUserList::slotAddAuthFirend);//认证通过
    connect(tcpMgr::getInstance().get(),&tcpMgr::sig_auth_rsp, this, &contactUserList::slotAuthRsp);//同意后回包
}
void contactUserList::showRedPoint(bool bshow )
{
    _addFriendItem->showRedPoint(bshow);
}

void contactUserList::addContactUserList()
{
    auto * groupTip = new groupTipItem();
    QListWidgetItem *item = new QListWidgetItem;
    item->setSizeHint(groupTip->sizeHint());
    this->addItem(item);
    this->setItemWidget(item, groupTip);
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);

    _addFriendItem = new conUserItem();
    _addFriendItem->setObjectName("new_friend_item");
    _addFriendItem->setInfo(0,tr("新的朋友"),":/res/add_friend.png");
    _addFriendItem->setItemType(ListItemType::APPLY_FRIEND_ITEM);

    QListWidgetItem *add_item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    add_item->setSizeHint(_addFriendItem->sizeHint());
    this->addItem(add_item);
    this->setItemWidget(add_item, _addFriendItem);

    //默认设置新的朋友申请条目被选中
    this->setCurrentItem(add_item);

    auto * groupCon = new groupTipItem();
    groupCon->SetGroupTip(tr("联系用户"));
    _groupitem = new QListWidgetItem;
    _groupitem->setSizeHint(groupCon->sizeHint());
    this->addItem(_groupitem);
    this->setItemWidget(_groupitem, groupCon);
    _groupitem->setFlags(_groupitem->flags() & ~Qt::ItemIsSelectable);


    // 创建QListWidgetItem，并设置自定义的widget
    for(int i = 0; i < 13; i++){
        int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
        int str_i = randomValue%strs.size();
        int head_i = randomValue%heads.size();
        int name_i = randomValue%names.size();

        auto *con_user_wid = new conUserItem();
        con_user_wid->setInfo(0,names[name_i], heads[head_i]);
        QListWidgetItem *item = new QListWidgetItem;
        //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
        item->setSizeHint(con_user_wid->sizeHint());
        this->addItem(item);
        this->setItemWidget(item, con_user_wid);
    }
}

bool contactUserList::eventFilter(QObject *watched, QEvent *event)
{
    // 检查事件是否是鼠标悬浮进入或离开
    if (watched == this->viewport()) {
        if (event->type() == QEvent::Enter) {
            // 鼠标悬浮，显示滚动条
            this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        } else if (event->type() == QEvent::Leave) {
            // 鼠标离开，隐藏滚动条
            this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }
    }

    // 检查事件是否是鼠标滚轮事件
    if (watched == this->viewport() && event->type() == QEvent::Wheel) {
        QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);
        int numDegrees = wheelEvent->angleDelta().y() / 8;
        int numSteps = numDegrees / 15; // 计算滚动步数

        // 设置滚动幅度
        this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - numSteps);

        // 检查是否滚动到底部
        QScrollBar *scrollBar = this->verticalScrollBar();
        int maxScrollValue = scrollBar->maximum();
        int currentValue = scrollBar->value();
        //int pageSize = 10; // 每页加载的联系人数量

        if (maxScrollValue - currentValue <= 0) {

            auto b_loaded = UserMgr::getInstance()->IsLoadChatFin();
            if(b_loaded){
                return true;
            }

            if(_load_pending){
                return true;
            }

            _load_pending = true;

            QTimer::singleShot(100, [this](){
                _load_pending = false;
                QCoreApplication::quit(); // 完成后退出应用程序
            });
            // 滚动到底部，加载新的联系人
            qDebug()<<"load more contact user";
            //发送信号通知聊天界面加载更多聊天内容
            emit sig_loading_contact_user();
        }

        return true; // 停止事件传递
    }

    return QListWidget::eventFilter(watched, event);

}

void contactUserList::slotItemClicked(QListWidgetItem *item)
{
    QWidget *widget = this->itemWidget(item); // 获取自定义widget对象
    if(!widget){
        qDebug()<< "slot item clicked widget is nullptr";
        return;
    }

    // 对自定义widget进行操作， 将item 转化为基类ListItemBase
    listItemBase *customItem = qobject_cast<listItemBase*>(widget);
    if(!customItem){
        qDebug()<< "slot item clicked widget is nullptr";
        return;
    }

    auto itemType = customItem->getItemType();
    if(itemType == ListItemType::INVALID_ITEM
        || itemType == ListItemType::GROUP_TIP_ITEM){
        qDebug()<< "slot invalid item clicked ";
        return;
    }

    if(itemType == ListItemType::APPLY_FRIEND_ITEM){

        // 创建对话框，提示用户
        qDebug()<< "apply friend item clicked ";
        //跳转到好友申请界面
        emit sig_switch_apply_friend_page();
        return;
    }

    if(itemType == ListItemType::CONTACT_USER_ITEM){
        // 创建对话框，提示用户
        qDebug()<< "contact user item clicked ";

        auto con_item = qobject_cast<conUserItem*>(customItem);
        auto user_info = con_item->GetInfo();
        //跳转到好友申请界面
        emit sig_switch_friend_info_page(user_info);
        return;
    }
}

void contactUserList::slotAddAuthFirend(std::shared_ptr<AuthInfo> auth_info)
{
    qDebug() << "slot add auth friend ";
    bool isFriend = UserMgr::getInstance()->CheckFriendById(auth_info->_uid);
    if(isFriend){
        return;
    }
    // 在 groupitem 之后插入新项
    int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
    int str_i = randomValue%strs.size();
    int head_i = randomValue%heads.size();

    auto *con_user_wid = new conUserItem();
    con_user_wid->setInfo(auth_info);
    QListWidgetItem *item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(con_user_wid->sizeHint());

    // 获取 groupitem 的索引
    int index = this->row(_groupitem);
    // 在 groupitem 之后插入新项
    this->insertItem(index + 1, item);

    this->setItemWidget(item, con_user_wid);


}

void contactUserList::slotAuthRsp(std::shared_ptr<AuthRsp> auth_rsp)
{
    qDebug() << "slot auth rsp called";
    bool isFriend = UserMgr::getInstance()->CheckFriendById(auth_rsp->_uid);
    if(isFriend){
        return;
    }
    // 在 groupitem 之后插入新项
    int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
    int str_i = randomValue%strs.size();
    int head_i = randomValue%heads.size();

    auto *con_user_wid = new conUserItem();
    con_user_wid->setInfo(auth_rsp->_uid ,auth_rsp->_name, heads[head_i]);
    QListWidgetItem *item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(con_user_wid->sizeHint());

    // 获取 groupitem 的索引
    int index = this->row(_groupitem);
    // 在 groupitem 之后插入新项
    this->insertItem(index + 1, item);

    this->setItemWidget(item, con_user_wid);


}
