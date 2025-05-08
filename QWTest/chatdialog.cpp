#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QAction>//制作触发功能
#include <QRandomGenerator>
#include <QMouseEvent>
#include <QPoint>
#include "chatuserwid.h"
#include "loadingdlg.h"
#include "tcpMgr.h"
#include "usermgr.h"
#include "conuseritem.h"
chatDialog::chatDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chatDialog),_mode(ChatUIMode::ChatMode),_state(ChatUIMode::ChatMode),_b_loading(false)
{
    ui->setupUi(this);
    ui->addBtn->SetState("normal","hover","press");

    ui->searchEdit->SetMaxLength(13);

    QAction *searchAction = new QAction(ui->searchEdit);
    searchAction->setIcon(QIcon(":/res/search.png"));
    ui->searchEdit->addAction(searchAction,QLineEdit::LeadingPosition);
    ui->searchEdit->setPlaceholderText(QStringLiteral("搜索"));

    QAction *clearAction = new QAction(ui->searchEdit);
    clearAction->setIcon(QIcon(":/res/close_transparent.png"));//清除动作图标
    //初始不显示，清楚图标加到尾部
    ui->searchEdit->addAction(clearAction,QLineEdit::TrailingPosition);

    connect(ui->searchEdit, &QLineEdit::textChanged, [clearAction](const QString &text){
        if(!text.isEmpty()){
            clearAction->setIcon(QIcon(":/res/close_search.png"));
        }
        else {
            clearAction->setIcon(QIcon(":/res/close_transparent.png"));
        }
    });

 // 连接清除动作的触发信号到槽函数清除文本
    connect(clearAction, &QAction::triggered, [this, clearAction]() {
        ui->searchEdit->clear();
        clearAction->setIcon(QIcon(":/res/close_transparent.png")); // 清除文本后，切换回透明图标
        ui->searchEdit->clearFocus();//失去焦点
        showSearch(false);//按下清除按钮后不显示搜索框
    });

    showSearch(false);

    connect(ui->chatUserlist, &chatUserList::sig_loading_chat_user, this,&chatDialog::slot_loading_chat_user);
    addChatUserList();
    addConUserList();
    ui->searchEdit->SetMaxLength(17);

    QPixmap pixmap(":/res/head_1.jpg");
    ui->sideHeadLb->setPixmap(pixmap); // 将图片设置到QLabel上
    QPixmap scaledPixmap = pixmap.scaled( ui->sideHeadLb->size(), Qt::KeepAspectRatio); // 图片缩放
    ui->sideHeadLb->setPixmap(scaledPixmap); // 将缩放后的图片设置到QLabel上
    ui->sideHeadLb->setScaledContents(true); // 设置QLabel自动缩放图片内容以适应大小

    ui->sideChatLb->setProperty("state","normal");

    ui->sideChatLb->setState("normal","hover","pressed","selected_normal","selected_hover","selected_pressed");

    ui->sideContactLb->setState("normal","hover","pressed","selected_normal","selected_hover","selected_pressed");

    addLBGroup(ui->sideChatLb);
    addLBGroup(ui->sideContactLb);

    connect(ui->sideChatLb, &stateWidget::clicked, this, &chatDialog::slot_side_chat);
    connect(ui->sideContactLb, &stateWidget::clicked, this, &chatDialog::slot_side_contact);

    //连接搜索框改变
    connect(ui->searchEdit, &QLineEdit::textChanged, this,&chatDialog::slot_text_changed);
    showSearch(false);
    //检测鼠标点击位置判断是否清除
    //安装事件过滤器
    this->installEventFilter(this);
    //默认聊天页面
    ui->sideChatLb->setSelected(true);

    //设置选中条目
    SetSelectChatItem();
    //更新聊天界面信息
    SetSelectChatPage();

    //连接加载联系人的信号和槽函数
    connect(ui->conUserList, &contactUserList::sig_loading_contact_user,
            this, &chatDialog::slot_loading_contact_user);

    //连接联系人页面点击好友申请条目的信号
    connect(ui->conUserList, &contactUserList::sig_switch_apply_friend_page,
            this,&chatDialog::slot_switch_apply_friend_page);

    //连接清除搜索框操作
    connect(ui->friend_apply_page, &applyFriendPage::sig_show_search, this, &chatDialog::slot_show_search);

    //为searchlist 设置search edit
    ui->searchLists->setSearchEdit(ui->searchEdit);

    //连接申请添加好友信号
    connect(tcpMgr::getInstance().get(), &tcpMgr::sig_friend_apply, this, &chatDialog::slot_apply_friend);

    //连接认证添加好友信号
    connect(tcpMgr::getInstance().get(), &tcpMgr::sig_add_auth_friend, this, &chatDialog::slot_add_auth_friend);

    //连接自己认证回复信号
    connect(tcpMgr::getInstance().get(), &tcpMgr::sig_auth_rsp, this,
            &chatDialog::slot_auth_rsp);

    //连接点击联系人item发出的信号和用户信息展示槽函数
    connect(ui->conUserList, &contactUserList::sig_switch_friend_info_page,
            this,&chatDialog::slot_friend_info_page);

    //设置中心部件为chatpage
    ui->stackedWidget->setCurrentWidget(ui->chat_page);


    //连接searchlist跳转聊天信号
    connect(ui->searchLists, &searchList::sig_jump_chat_item, this, &chatDialog::slot_jump_chat_item);

    //连接好友信息界面发送的点击事件
    connect(ui->friend_info_page, &FriendInfoPage::sig_jump_chat_item, this,
            &chatDialog::slot_jump_chat_item_from_infopage);

    //连接聊天列表点击信号
    connect(ui->chatUserlist, &QListWidget::itemClicked, this, &chatDialog::slot_item_clicked);

    //连接对端消息通知
    connect(tcpMgr::getInstance().get(), &tcpMgr::sig_text_chat_msg,
            this, &chatDialog::slot_text_chat_msg);

    connect(ui->chat_page, &chatPage::sig_append_send_chat_msg, this, &chatDialog::slot_append_send_chat_msg);
}

chatDialog::~chatDialog()
{
    delete ui;
}
void chatDialog::addChatUserList()
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
    auto friend_list = UserMgr::getInstance()->GetChatListPerPage();
    if (friend_list.empty() == false) {
        for(auto & friend_ele : friend_list){
            auto find_iter = _chat_items_added.find(friend_ele->_uid);
            if(find_iter != _chat_items_added.end()){
                continue;
            }
            auto *chat_user_wid = new chatUserWid();
            auto user_info = std::make_shared<UserInfo>(friend_ele);
            chat_user_wid->SetInfo(user_info);
            QListWidgetItem *item = new QListWidgetItem;
            //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
            item->setSizeHint(chat_user_wid->sizeHint());
            ui->chatUserlist->addItem(item);
            ui->chatUserlist->setItemWidget(item, chat_user_wid);
            _chat_items_added.insert(friend_ele->_uid, item);
        }

        //更新已加载条目
        UserMgr::getInstance()->UpdateChatLoadedCount();
    }

    //模拟测试条目
    // 创建QListWidgetItem，并设置自定义的widget
    for(int i = 0; i < 50; i++){
        int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
        int str_i = randomValue%strs.size();
        int head_i = randomValue%heads.size();
        int name_i = randomValue%names.size();

        auto *chat_user_wid = new chatUserWid();
        auto user_info = std::make_shared<UserInfo>(0,names[name_i],
                                                    names[name_i],heads[head_i],0,strs[str_i]);
        chat_user_wid->SetInfo(user_info);
        QListWidgetItem *item = new QListWidgetItem;
        //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
        item->setSizeHint(chat_user_wid->sizeHint());
        ui->chatUserlist->addItem(item);
        ui->chatUserlist->setItemWidget(item, chat_user_wid);
    }

}

void chatDialog::clearLabelState(stateWidget *lb)
{
    for(auto & e:_lb_list){
        if(e == lb)continue;
        e->clearState();
    }
}

bool chatDialog::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        //鼠标点击事件
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        handleGlobalMousePress(mouseEvent);
    }

    return QDialog::eventFilter(watched,event);
}

void chatDialog::handleGlobalMousePress(QMouseEvent *event)
{
    //不在搜索模式则跳过
    if(_mode !=ChatUIMode::SearchMode){
        return;
    }

    QPoint posInSearchList = ui->searchLists->mapFromGlobal(event->globalPosition().toPoint());//转成整数位置

    if(!ui->searchLists->rect().contains(posInSearchList)){
        //不在聊天列表中清空输入
        ui->searchEdit->clear();
        showSearch(false);
    }
}

void chatDialog::CloseFindDlg()
{
    ui->searchLists->closeFindDlg();
}
void chatDialog::UpdateChatMsg(std::vector<std::shared_ptr<TextChatData> > msgdata)
{
    for(auto & msg : msgdata){
        if(msg->_from_uid != _cur_chat_uid){
            break;
        }

        ui->chat_page->AppendChatMsg(msg);
    }
}
void chatDialog::showSearch(bool bsearch)
{
    if(bsearch){
        ui->chatUserlist->hide();
        ui->conUserList->hide();
        ui->searchLists->show();
        _mode = ChatUIMode::SearchMode;
    }else if(_state == ChatUIMode::ChatMode){
        ui->chatUserlist->show();
        ui->conUserList->hide();
        ui->searchLists->hide();
        _mode = ChatUIMode::ChatMode;
    }else if(_state == ChatUIMode::ContactMode){
        ui->chatUserlist->hide();
        ui->conUserList->show();
        ui->searchLists->hide();
        _mode = ChatUIMode::ContactMode;
    }
}

void chatDialog::addLBGroup(stateWidget *lb)
{
   _lb_list.push_back(lb);
}

void chatDialog::loadMoreChatUser()
{
    auto friend_list = UserMgr::getInstance()->GetChatListPerPage();
    if (friend_list.empty() == false) {
        for(auto & friend_ele : friend_list){
            auto find_iter = _chat_items_added.find(friend_ele->_uid);
            if(find_iter != _chat_items_added.end()){
                continue;
            }
            auto *chat_user_wid = new chatUserWid();
            auto user_info = std::make_shared<UserInfo>(friend_ele);
            chat_user_wid->SetInfo(user_info);
            QListWidgetItem *item = new QListWidgetItem;
            //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
            item->setSizeHint(chat_user_wid->sizeHint());
            ui->chatUserlist->addItem(item);
            ui->chatUserlist->setItemWidget(item, chat_user_wid);
            _chat_items_added.insert(friend_ele->_uid, item);
        }

        //更新已加载条目
        UserMgr::getInstance()->UpdateChatLoadedCount();
    }
}

void chatDialog::ClearLabelState(stateWidget *lb)
{
    for(auto & ele: _lb_list){
        if(ele == lb){
            continue;
        }

        ele->clearState();
    }
}

void chatDialog::loadMoreConUser()
{
    auto friend_list = UserMgr::getInstance()->GetConListPerPage();
    if (friend_list.empty() == false) {
        for(auto & friend_ele : friend_list){
            auto *chat_user_wid = new conUserItem();
            chat_user_wid->setInfo(friend_ele->_uid,friend_ele->_name,
                                   friend_ele->_icon);
            QListWidgetItem *item = new QListWidgetItem;
            //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
            item->setSizeHint(chat_user_wid->sizeHint());
            ui->conUserList->addItem(item);
            ui->conUserList->setItemWidget(item, chat_user_wid);
        }

        //更新已加载条目
        UserMgr::getInstance()->UpdateContactLoadedCount();
    }
}
void chatDialog::addConUserList(){
    auto friend_list = UserMgr::getInstance()->GetChatListPerPage();
    if (friend_list.empty() == false) {
        for(auto & friend_ele : friend_list){
            auto *chat_user_wid = new conUserItem();
            chat_user_wid->setInfo(friend_ele->_uid,friend_ele->_name,
                                   friend_ele->_icon);
            QListWidgetItem *item = new QListWidgetItem;
            //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
            item->setSizeHint(chat_user_wid->sizeHint());
            ui->conUserList->addItem(item);
            ui->conUserList->setItemWidget(item, chat_user_wid);
        }

        //更新已加载条目
        UserMgr::getInstance()->UpdateContactLoadedCount();
    }
}
void chatDialog::SetSelectChatItem(int uid)
{
    if(ui->chatUserlist->count() <= 0){
        return;
    }

    if(uid == 0){
        ui->chatUserlist->setCurrentRow(0);
        QListWidgetItem *firstItem = ui->chatUserlist->item(0);
        if(!firstItem){
            return;
        }

        //转为widget
        QWidget *widget = ui->chatUserlist->itemWidget(firstItem);
        if(!widget){
            return;
        }

        auto con_item = qobject_cast<chatUserWid*>(widget);
        if(!con_item){
            return;
        }

        _cur_chat_uid = con_item->GetUserInfo()->_uid;

        return;
    }

    auto find_iter = _chat_items_added.find(uid);
    if(find_iter == _chat_items_added.end()){
        qDebug() << "uid " <<uid<< " not found, set curent row 0";
        ui->chatUserlist->setCurrentRow(0);
        return;
    }

    ui->chatUserlist->setCurrentItem(find_iter.value());

    _cur_chat_uid = uid;
}

void chatDialog::SetSelectChatPage(int uid)
{
    if( ui->chatUserlist->count() <= 0){
        return;
    }

    if (uid == 0) {
        auto item = ui->chatUserlist->item(0);
        //转为widget
        QWidget* widget = ui->chatUserlist->itemWidget(item);
        if (!widget) {
            return;
        }

        auto con_item = qobject_cast<chatUserWid*>(widget);
        if (!con_item) {
            return;
        }

        //设置信息
        auto user_info = con_item->GetUserInfo();
        ui->chat_page->SetUserInfo(user_info);
        return;
    }

    auto find_iter = _chat_items_added.find(uid);
    if(find_iter == _chat_items_added.end()){
        return;
    }

    //转为widget
    QWidget *widget = ui->chatUserlist->itemWidget(find_iter.value());
    if(!widget){
        return;
    }

    //判断转化为自定义的widget
    // 对自定义widget进行操作， 将item 转化为基类ListItemBase
    listItemBase *customItem = qobject_cast<listItemBase*>(widget);
    if(!customItem){
        qDebug()<< "qobject_cast<ListItemBase*>(widget) is nullptr";
        return;
    }

    auto itemType = customItem->getItemType();
    if(itemType == CHAT_USER_ITEM){
        auto con_item = qobject_cast<chatUserWid*>(customItem);
        if(!con_item){
            return;
        }

        //设置信息
        auto user_info = con_item->GetUserInfo();
        ui->chat_page->SetUserInfo(user_info);

        return;
    }
}

void chatDialog::slot_loading_chat_user()
{
    if(_b_loading)
        return ;
    _b_loading = true;//防止多次重复加载
    loadingDlg * loadingDialog = new loadingDlg(this);
    loadingDialog->setModal(true);
    loadingDialog->show();
    qDebug()<<"add new data for list";
    addChatUserList();
    //加载完成
    loadingDialog->deleteLater();

    _b_loading = false;
}

void chatDialog::slot_side_chat()
{
    qDebug()<< "receive side chat clicked";
    clearLabelState(ui->sideChatLb);
    ui->stackedWidget->setCurrentWidget(ui->chat_page);
    _state = ChatUIMode::ChatMode;
    showSearch(false);
}

void chatDialog::slot_side_contact()
{
    qDebug()<< "receive side contact clicked";
    clearLabelState(ui->sideContactLb);
    ui->stackedWidget->setCurrentWidget(ui->friend_apply_page);
    _state = ChatUIMode::ContactMode;
    showSearch(false);
}

void chatDialog::slot_text_changed(const QString &str)
{
    if(!str.isEmpty())showSearch(true);
}

void chatDialog::slot_apply_friend(std::shared_ptr<AddFriendApply> apply)
{
    qDebug() << "receive apply friend slot, applyuid is " << apply->_from_uid << " name is "
             << apply->_name << " desc is " << apply->_desc;

    bool b_already = UserMgr::getInstance()->AlreadyApply(apply->_from_uid);
    if(b_already){
        return;
    }

    UserMgr::getInstance()->AddApplyList(std::make_shared<ApplyInfo>(apply));
    ui->sideContactLb->showRedPoint(true);
    ui->conUserList->showRedPoint(true);
    ui->friend_apply_page->addNewApply(apply);
}

void chatDialog::slot_add_auth_friend(std::shared_ptr<AuthInfo> auth_info)
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
    qDebug() << "receive slot_add_auth__friend uid is " << auth_info->_uid
             << " name is " << auth_info->_name << " nick is " << auth_info->_nick;

    //判断如果已经是好友则跳过
    auto bfriend = UserMgr::getInstance()->CheckFriendById(auth_info->_uid);
    if(bfriend){
        return;
    }

    UserMgr::getInstance()->AddFriend(auth_info);

    int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
    int str_i = randomValue % strs.size();
    int head_i = randomValue % heads.size();
    int name_i = randomValue % names.size();

    auto* chat_user_wid = new chatUserWid();
    auto user_info = std::make_shared<UserInfo>(auth_info);
    chat_user_wid->SetInfo(user_info);
    QListWidgetItem* item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(chat_user_wid->sizeHint());
    ui->chatUserlist->insertItem(0, item);
    ui->chatUserlist->setItemWidget(item, chat_user_wid);
    _chat_items_added.insert(auth_info->_uid, item);

}

void chatDialog::slot_auth_rsp(std::shared_ptr<AuthRsp> auth_rsp)
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
    qDebug() << "receive slot_auth_rsp uid is " << auth_rsp->_uid
             << " name is " << auth_rsp->_name << " nick is " << auth_rsp->_nick;

    //判断如果已经是好友则跳过
    auto bfriend = UserMgr::getInstance()->CheckFriendById(auth_rsp->_uid);
    if(bfriend){
        return;
    }

    UserMgr::getInstance()->AddFriend(auth_rsp);
    int randomValue = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机整数
    int str_i = randomValue % strs.size();
    int head_i = randomValue % heads.size();
    int name_i = randomValue % names.size();

    auto* chat_user_wid = new chatUserWid();
    auto user_info = std::make_shared<UserInfo>(auth_rsp);
    chat_user_wid->SetInfo(user_info);
    QListWidgetItem* item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(chat_user_wid->sizeHint());
    ui->chatUserlist->insertItem(0, item);
    ui->chatUserlist->setItemWidget(item, chat_user_wid);
    _chat_items_added.insert(auth_rsp->_uid, item);

}

void chatDialog::slot_focus_out()
{
    qDebug()<< "receive focus out signal";
    showSearch(false);
}

void chatDialog::slot_loading_contact_user()
{
    qDebug() << "slot loading contact user";
    if(_b_loading){
        return;
    }

    _b_loading = true;
    loadingDlg *loadingDialog = new loadingDlg(this);
    loadingDialog->setModal(true);
    loadingDialog->show();
    qDebug() << "add new data to list.....";
    loadMoreConUser();
    // 加载完成后关闭对话框
    loadingDialog->deleteLater();

    _b_loading = false;
}

void chatDialog::slot_switch_apply_friend_page()
{
    qDebug()<<"receive switch apply friend page sig";
    _last_widget = ui->friend_apply_page;
    ui->stackedWidget->setCurrentWidget(ui->friend_apply_page);
}

void chatDialog::slot_friend_info_page(std::shared_ptr<UserInfo> user_info)
{
    qDebug()<<"receive switch friend info page sig";
    _last_widget = ui->friend_info_page;
    ui->stackedWidget->setCurrentWidget(ui->friend_info_page);
    ui->friend_info_page->SetInfo(user_info);
}

void chatDialog::slot_show_search(bool show)
{
    showSearch(show);
}

void chatDialog::slot_jump_chat_item(std::shared_ptr<searchInfo> si)
{
    qDebug() << "slot jump chat item " << "\n";
    auto find_iter = _chat_items_added.find(si->_uid);
    if(find_iter != _chat_items_added.end()){
        qDebug() << "jump to chat item , uid is " << si->_uid;
        ui->chatUserlist->scrollToItem(find_iter.value());
        ui->sideChatLb->setSelected(true);
        SetSelectChatItem(si->_uid);
        //更新聊天界面信息
        SetSelectChatPage(si->_uid);
        slot_side_chat();
        return;
    }

    //如果没找到，则创建新的插入listwidget

    auto* chat_user_wid = new chatUserWid();
    auto user_info = std::make_shared<UserInfo>(si);
    chat_user_wid->SetInfo(user_info);
    QListWidgetItem* item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(chat_user_wid->sizeHint());
    ui->chatUserlist->insertItem(0, item);
    ui->chatUserlist->setItemWidget(item, chat_user_wid);

    _chat_items_added.insert(si->_uid, item);

    ui->sideChatLb->setSelected(true);
    SetSelectChatItem(si->_uid);
    //更新聊天界面信息
    SetSelectChatPage(si->_uid);
    slot_side_chat();

}

void chatDialog::slot_jump_chat_item_from_infopage(std::shared_ptr<UserInfo> user_info)
{
    qDebug() << "slot jump chat item " << "\n";
    auto find_iter = _chat_items_added.find(user_info->_uid);
    if(find_iter != _chat_items_added.end()){
        qDebug() << "jump to chat item , uid is " << user_info->_uid;
        ui->chatUserlist->scrollToItem(find_iter.value());
        ui->sideChatLb->setSelected(true);
        SetSelectChatItem(user_info->_uid);
        //更新聊天界面信息
        SetSelectChatPage(user_info->_uid);
        slot_side_chat();
        return;
    }

    //如果没找到，则创建新的插入listwidget

    auto* chat_user_wid = new chatUserWid();
    chat_user_wid->SetInfo(user_info);
    QListWidgetItem* item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(chat_user_wid->sizeHint());
    ui->chatUserlist->insertItem(0, item);
    ui->chatUserlist->setItemWidget(item, chat_user_wid);

    _chat_items_added.insert(user_info->_uid, item);

    ui->sideChatLb->setSelected(true);
    SetSelectChatItem(user_info->_uid);
    //更新聊天界面信息
    SetSelectChatPage(user_info->_uid);
    slot_side_chat();
}

void chatDialog::slot_item_clicked(QListWidgetItem *item)
{
    QWidget *widget = ui->chatUserlist->itemWidget(item); // 获取自定义widget对象
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


    if(itemType == ListItemType::CHAT_USER_ITEM){
        // 创建对话框，提示用户
        qDebug()<< "contact user item clicked ";

        auto chat_wid = qobject_cast<chatUserWid*>(customItem);
        auto user_info = chat_wid->GetUserInfo();
        //跳转到聊天界面
        ui->chat_page->SetUserInfo(user_info);
        _cur_chat_uid = user_info->_uid;
        return;
    }
}

void chatDialog::slot_text_chat_msg(std::shared_ptr<TextChatMsg> msg)
{
    auto find_iter = _chat_items_added.find(msg->_from_uid);
    if(find_iter != _chat_items_added.end()){
        qDebug() << "set chat item msg, uid is " << msg->_from_uid;
        QWidget *widget = ui->chatUserlist->itemWidget(find_iter.value());
        auto chat_wid = qobject_cast<chatUserWid*>(widget);
        if(!chat_wid){
            return;
        }
        chat_wid->updateLastMsg(msg->_chat_msgs);
        //更新当前聊天页面记录
        UpdateChatMsg(msg->_chat_msgs);
        UserMgr::getInstance()->AppendFriendChatMsg(msg->_from_uid,msg->_chat_msgs);
        return;
    }

    //如果没找到，则创建新的插入listwidget

    auto* chat_user_wid = new chatUserWid();
    //查询好友信息
    auto fi_ptr = UserMgr::getInstance()->GetFriendById(msg->_from_uid);
    chat_user_wid->SetInfo(fi_ptr);
    QListWidgetItem* item = new QListWidgetItem;
    //qDebug()<<"chat_user_wid sizeHint is " << chat_user_wid->sizeHint();
    item->setSizeHint(chat_user_wid->sizeHint());
    chat_user_wid->updateLastMsg(msg->_chat_msgs);
    UserMgr::getInstance()->AppendFriendChatMsg(msg->_from_uid,msg->_chat_msgs);
    ui->chatUserlist->insertItem(0, item);
    ui->chatUserlist->setItemWidget(item, chat_user_wid);
    _chat_items_added.insert(msg->_from_uid, item);

}

void chatDialog::slot_append_send_chat_msg(std::shared_ptr<TextChatData> msgdata)
{
    if (_cur_chat_uid == 0) {
        return;
    }

    auto find_iter = _chat_items_added.find(_cur_chat_uid);
    if (find_iter == _chat_items_added.end()) {
        return;
    }

    //转为widget
    QWidget* widget = ui->chatUserlist->itemWidget(find_iter.value());
    if (!widget) {
        return;
    }

    //判断转化为自定义的widget
    // 对自定义widget进行操作， 将item 转化为基类ListItemBase
    listItemBase* customItem = qobject_cast<listItemBase*>(widget);
    if (!customItem) {
        qDebug() << "qobject_cast<ListItemBase*>(widget) is nullptr";
        return;
    }

    auto itemType = customItem->getItemType();
    if (itemType == CHAT_USER_ITEM) {
        auto con_item = qobject_cast<chatUserWid*>(customItem);
        if (!con_item) {
            return;
        }

        //设置信息
        auto user_info = con_item->GetUserInfo();
        user_info->_chat_msgs.push_back(msgdata);
        std::vector<std::shared_ptr<TextChatData>> msg_vec;
        msg_vec.push_back(msgdata);
        UserMgr::getInstance()->AppendFriendChatMsg(_cur_chat_uid,msg_vec);
        return;
    }
}


