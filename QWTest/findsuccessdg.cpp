#include "findsuccessdg.h"
#include "ui_findsuccessdg.h"
#include <QDir>
#include "applyFriend.h"
findSuccessDg::findSuccessDg(QWidget *parent)
    : QDialog(parent), _parent(parent)
    , ui(new Ui::findSuccessDg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);//隐藏边框

    QString appPath = QCoreApplication::applicationDirPath();
    /*QString pixPath = QDir::toNativeSeparators(appPath + QDir::separator() + "static" + QDir::separator()+"head_1.jpg");//图片路径
    QPixmap headPix(pixPath);*/
    QPixmap headPix(":/res/head_5.jpg");
    headPix = headPix.scaled(ui->head_lb->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->head_lb->setPixmap(headPix);
    ui->add_friend_btn->SetState("normal","hover","press");
    this->setModal(true);
}

findSuccessDg::~findSuccessDg()
{
    qDebug()<<"findSusscessDg is close";
    delete ui;
}

void findSuccessDg::setSearchInfo(std::shared_ptr<searchInfo> si)
{
    ui->name_lb->setText(si->_name);
    _si = si;
}

void findSuccessDg::on_add_friend_btn_clicked()
{
    qDebug() << "Hiding current window";
    this->hide();
    qDebug() << "Current window hidden";
    //弹出加好友界面
    // 打印父窗口信息
    if (_parent) {
        qDebug() << "_parent is valid";
    } else {
        qDebug() << "_parent is nullptr";
    }
    // 创建并设置新的添加好友窗口
    auto apply = new applyFriend(_parent ? _parent : this);  // 如果 _parent 为 nullptr，使用当前窗口作为父窗口
    qDebug() << "Created applyFriend window";

    /*if (apply == nullptr) {
        qDebug() << "apply object is null";
    } else {
        qDebug() << "apply object is valid";
    }

    // 设置相关信息
    if (_si) {//测试使用
        qDebug() << "Search Info - UID:" << _si->_uid
                 << ", Name:" << _si->_name
                 << ", Nick:" << _si->_nick
                 << ", Desc:" << _si->_desc
                 << ", Sex:" << _si->_sex
                 << ", Icon:" << _si->_icon;
    } else {
        _si->_uid = 123;
        _si->_name = "123";
        _si->_nick = "156";
        _si->_desc = "146";
        _si->_sex = 1;
        _si->_icon =  ":/res/head_1.jpg";
        qDebug()<<"测试使用的问题";
    }*/
    apply->SetSearchInfo(_si);

    apply->setModal(true);
    apply->show();
}
