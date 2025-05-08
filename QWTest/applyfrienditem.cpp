#include "applyfrienditem.h"
#include "ui_applyfrienditem.h"
#include <qDebug>
applyFriendItem::applyFriendItem(QWidget *parent)
    : listItemBase(parent),_added(false), ui(new Ui::applyFriendItem)
{
    ui->setupUi(this);
    setItemType(ListItemType::APPLY_FRIEND_ITEM);
    ui->addBtn->SetState("normal","hover", "press");
    ui->addBtn->hide();
    connect(ui->addBtn, &clickBtn::clicked,  [this](){
        emit this->sig_auth_friend(_apply_info);
        qDebug()<<"sig_auth_friend clicked";
    });
}

applyFriendItem::~applyFriendItem()
{
    delete ui;
}
void applyFriendItem::SetInfo(std::shared_ptr<ApplyInfo> apply_info)
{
    _apply_info = apply_info;
    // 加载图片
    QPixmap pixmap(_apply_info->_icon);

    // 设置图片自动缩放
    ui->icon_lb->setPixmap(pixmap.scaled(ui->icon_lb->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->icon_lb->setScaledContents(true);

    ui->user_name_lb->setText(_apply_info->_name);
    ui->user_chat_lb->setText(_apply_info->_desc);
}

void applyFriendItem::ShowAddBtn(bool bshow)
{
    if (bshow) {
        ui->addBtn->show();
        ui->already_add_lb->hide();
        _added = false;
    }
    else {
        ui->addBtn->hide();
        ui->already_add_lb->show();
        _added = true;
    }
}

int applyFriendItem::GetUid() {
    return _apply_info->_uid;
}
