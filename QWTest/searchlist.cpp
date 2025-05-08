#include "searchlist.h"
#include "tcpmgr.h"
#include "addUserItem.h"
#include "findsuccessdg.h"
#include "customEdit.h"
#include "userMgr.h"
#include "findfaildlg.h"
searchList::searchList(QWidget* parent) :QListWidget(parent), _find_dg(nullptr), _search_edit(nullptr), _send_pending(false)
{
	Q_UNUSED(parent);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// 安装事件过滤器
	this->viewport()->installEventFilter(this);
	//连接点击的信号和槽
	connect(this, &QListWidget::itemClicked, this, &searchList::slot_item_clicked);
	//添加条目
	addTipItem();
	//连接搜索条目
	connect(tcpMgr::getInstance().get(), &tcpMgr::sig_user_search, this, &searchList::slot_user_search);
}

void searchList::closeFindDlg()
{
	if (_find_dg) {
		_find_dg->hide();
		_find_dg = nullptr;
	}
}

void searchList::setSearchEdit(QWidget* edit)
{
	_search_edit = edit;
}

bool searchList::eventFilter(QObject* watched, QEvent* event)
{

	// 检查事件是否是鼠标悬浮进入或离开
	if (watched == this->viewport()) {
		if (event->type() == QEvent::Enter) {
			// 鼠标悬浮，显示滚动条
			this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
		}
		else if (event->type() == QEvent::Leave) {
			// 鼠标离开，隐藏滚动条
			this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		}
	}

	// 检查事件是否是鼠标滚轮事件
	if (watched == this->viewport() && event->type() == QEvent::Wheel) {
		QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
		int numDegrees = wheelEvent->angleDelta().y() / 8;
		int numSteps = numDegrees / 15; // 计算滚动步数

		// 设置滚动幅度
		this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - numSteps);

		return true; // 停止事件传递
	}

	return QListWidget::eventFilter(watched, event);
}

void searchList::waitPending(bool pending)
{
	if (pending) {
		_loadingDialog = new loadingDlg(this);
		_loadingDialog->setModal(true);
		_loadingDialog->show();
		_send_pending = pending;
	}
	else {
		_loadingDialog->hide();
		_loadingDialog->deleteLater();
		_send_pending = pending;
	}
}

void searchList::addTipItem()
{
	auto* invalid_item = new QWidget();
	QListWidgetItem* item_tmp = new QListWidgetItem;



	item_tmp->setSizeHint(QSize(250, 10));
	this->addItem(item_tmp);
	invalid_item->setObjectName("invalid_item");
	this->setItemWidget(item_tmp, invalid_item);
	item_tmp->setFlags(item_tmp->flags() & ~Qt::ItemIsSelectable);


	auto* add_user_item = new addUserItem();
	QListWidgetItem* item = new QListWidgetItem;

	item->setSizeHint(add_user_item->sizeHint());
	this->addItem(item);
	this->setItemWidget(item, add_user_item);
}

void searchList::slot_item_clicked(QListWidgetItem* item)
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
    if(itemType == ListItemType::INVALID_ITEM){
        qDebug()<< "slot invalid item clicked ";
        return;
    }

    if(itemType == ListItemType::ADD_USER_TIP_ITEM){

        if (_send_pending) {
            return;
        }

        if (!_search_edit) {
            return;
        }
        waitPending(true);
        auto search_edit = dynamic_cast<customEdit*>(_search_edit);
        auto uid_str = search_edit->text();
        //此处发送请求给server
        QJsonObject jsonObj;
        jsonObj["uid"] = uid_str;

        QJsonDocument doc(jsonObj);
        QByteArray jsonData = doc.toJson(QJsonDocument::Compact);

        //发送tcp请求给chat server
        emit tcpMgr::getInstance()->sig_send_data(ReqId::ID_SEARCH_USER_REQ, jsonData);
        return;
    }

    //清除弹出框
    closeFindDlg();
}

void searchList::slot_user_search(std::shared_ptr<searchInfo> si)
{
	waitPending(false);
	if (si == nullptr) {
		_find_dg = std::make_shared<findFailDlg>(this);
	}
	else {
		//如果是自己，暂且先直接返回
		auto self_uid = UserMgr::getInstance()->GetUid();
		if (si->_uid == self_uid) {
			return;
		}
		//此处分两种情况，一种是搜多到已经是自己的朋友了，一种是未添加好友
		//查找是否已经是好友
		bool bExist = UserMgr::getInstance()->CheckFriendById(si->_uid);
		if (bExist) {
			//此处处理已经添加的好友，实现页面跳转
			//跳转到聊天界面指定的item中
            emit sig_jump_chat_item(si);
			return;
		}
		//此处先处理为添加的好友
		_find_dg = std::make_shared<findSuccessDg>(this);
		std::dynamic_pointer_cast<findSuccessDg>(_find_dg)->setSearchInfo(si);

	}
    _find_dg->show();    waitPending(false);
    if (si == nullptr) {
        _find_dg = std::make_shared<findFailDlg>(this);
    }else{
        //如果是自己，暂且先直接返回，以后看逻辑扩充
        auto self_uid = UserMgr::getInstance()->GetUid();
        if (si->_uid == self_uid) {
            return;
        }
        //此处分两种情况，一种是搜多到已经是自己的朋友了，一种是未添加好友
        //查找是否已经是好友
        bool bExist = UserMgr::getInstance()->CheckFriendById(si->_uid);
        if(bExist){
            //此处处理已经添加的好友，实现页面跳转
            //跳转到聊天界面指定的item中
            emit sig_jump_chat_item(si);
            return;
        }
        //此处先处理为添加的好友
        _find_dg = std::make_shared<findSuccessDg>(this);
        std::dynamic_pointer_cast<findSuccessDg>(_find_dg)->setSearchInfo(si);

    }
    _find_dg->show();
}
