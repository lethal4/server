#include "conuseritem.h"
#include "ui_conuseritem.h"

conUserItem::conUserItem(QWidget *parent):listItemBase(parent)
    , ui(new Ui::conUserItem)
{
    ui->setupUi(this);
    setItemType(ListItemType::CONTACT_USER_ITEM);
    ui->red_point->raise();//提升到Z坐标
    showRedPoint(false);
}

conUserItem::~conUserItem()
{
    delete ui;
}
QSize conUserItem::sizeHint() const
{
    return QSize(250, 70); // 返回自定义的尺寸
}

void conUserItem::setInfo(std::shared_ptr<AuthInfo> auth_info)
{
    _info = std::make_shared<UserInfo>(auth_info);
    // 加载图片
    QPixmap pixmap(_info->_icon);

    // 设置图片自动缩放
    ui->icon_lb->setPixmap(pixmap.scaled(ui->icon_lb->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->icon_lb->setScaledContents(true);

    ui->username_lb->setText(_info->_name);
}

void conUserItem::setInfo(int uid, QString name, QString icon)
{
    _info = std::make_shared<UserInfo>(uid,name, icon);

    // 加载图片
    QPixmap pixmap(_info->_icon);

    // 设置图片自动缩放
    ui->icon_lb->setPixmap(pixmap.scaled(ui->icon_lb->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->icon_lb->setScaledContents(true);

    ui->username_lb->setText(_info->_name);
}

void conUserItem::setInfo(std::shared_ptr<AuthRsp> auth_rsp){
    _info = std::make_shared<UserInfo>(auth_rsp);

    // 加载图片
    QPixmap pixmap(_info->_icon);

    // 设置图片自动缩放
    ui->icon_lb->setPixmap(pixmap.scaled(ui->icon_lb->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->icon_lb->setScaledContents(true);

    ui->username_lb->setText(_info->_name);
}

void conUserItem::showRedPoint(bool show)
{
    if(show){
        ui->red_point->show();
    }else{
        ui->red_point->hide();
    }

}

std::shared_ptr<UserInfo> conUserItem::GetInfo()
{
    return _info;
}
