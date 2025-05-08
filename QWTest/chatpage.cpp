#include "chatpage.h"
#include "ui_chatpage.h"
#include <QStyleOption>
#include <QPainter>
#include "textbubble.h"
#include "picturebubble.h"
#include "chatItemBase.h"
#include <QPixmap>
#include "applyfrienditem.h"
#include "usermgr.h"
#include <QJsonArray>
#include <QJsonObject>
#include "tcpmgr.h"
#include <QUuid>
#include <QRandomGenerator>
#include "messagetextedit.h"
chatPage::chatPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatPage)
{
    ui->setupUi(this);
    ui->receiveBtn->SetState("normal","hover","press");
    ui->sendBtn->SetState("normal","hover","press");
    //设置图标样式
    ui->emoLb->SetState("normal","hover","press","normal","hover","press");
    ui->fileLb->SetState("normal","hover","press","normal","hover","press");
    ui->receiveBtn->hide();

    connect(ui->chatEdit,&messageTextEdit::enterPressed,this,&chatPage::on_sendBtn_clicked);
}

chatPage::~chatPage()
{
    delete ui;
}

void chatPage::SetUserInfo(std::shared_ptr<UserInfo> user_info)
{
    _user_info = user_info;
    //设置ui界面
    ui->titleLb->setText(_user_info->_name);
    ui->chatDataList->removeAllItem();
    for(auto & msg : user_info->_chat_msgs){
        AppendChatMsg(msg);
    }
}

void chatPage::AppendChatMsg(std::shared_ptr<TextChatData> msg)
{
    auto self_info = UserMgr::getInstance()->GetUserInfo();
    ChatRole role;
    //todo... 添加聊天显示
    if (msg->_from_uid == self_info->_uid) {
        role = ChatRole::Self;
        chatItemBase* pChatItem = new chatItemBase(role);

        pChatItem->setUserName(":/res/head_5.jpg");

        QPixmap avatarPixmap(self_info->_icon);
        if (avatarPixmap.isNull()) {
            qDebug() << "Avatar is not valid: " << self_info->_icon;
            self_info->_icon=":/res/head_5.jpg";
            avatarPixmap = self_info->_icon;
        }
        pChatItem->setUserIcon(avatarPixmap);

        QWidget* pBubble = nullptr;
        pBubble = new textBubble(role, msg->_msg_content);
        pChatItem->setWidget(pBubble);
        ui->chatDataList->appendChatItem(pChatItem);
    }
    else {
        role = ChatRole::Other;
        chatItemBase* pChatItem = new chatItemBase(role);
        auto friend_info = UserMgr::getInstance()->GetFriendById(msg->_from_uid);
        if (friend_info == nullptr) {
            return;
        }
        pChatItem->setUserName(friend_info->_name);
        std::vector<QString> heads = {
            ":/res/head_1.jpg",
            ":/res/head_2.jpg",
            ":/res/head_3.jpg",
            ":/res/head_4.jpg",
            ":/res/head_5.jpg"
        };
        int randomValue = QRandomGenerator::global()->bounded(100);
        int head_i = randomValue % heads.size();
        pChatItem->setUserIcon(QPixmap(heads[head_i]));
        QWidget* pBubble = nullptr;
        pBubble = new textBubble(role, msg->_msg_content);
        pChatItem->setWidget(pBubble);
        qDebug()<<"friend_info "<<friend_info->_icon;
        ui->chatDataList->appendChatItem(pChatItem);
    }


}

void chatPage::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void chatPage::on_sendBtn_clicked()
{
    if (_user_info == nullptr) {
        qDebug() << "friend_info is empty";
        return;
    }

    auto user_info = UserMgr::getInstance()->GetUserInfo();
    auto pTextEdit = ui->chatEdit;
    ChatRole role = ChatRole::Self;
    QString userName = user_info->_name;
    QString userIcon = user_info->_icon;

    const QVector<MsgInfo>& msgList = pTextEdit->getMsgList();
    QJsonObject textObj;
    QJsonArray textArray;
    int txt_size = 0;

    for(int i=0; i<msgList.size(); ++i)
    {
        //消息内容长度不合规就跳过
        if(msgList[i].content.length() > 1024){
            continue;
        }

        QString type = msgList[i].msgFlag;
        chatItemBase *pChatItem = new chatItemBase(role);
        pChatItem->setUserName(userName);
        pChatItem->setUserIcon(QPixmap(userIcon));
        QWidget *pBubble = nullptr;

        if(type == "text")
        {
            //生成唯一id
            QUuid uuid = QUuid::createUuid();
            //转为字符串
            QString uuidString = uuid.toString();

            pBubble = new textBubble(role, msgList[i].content);
            if(txt_size + msgList[i].content.length()> 1024){
                textObj["fromuid"] = user_info->_uid;
                textObj["touid"] = _user_info->_uid;
                textObj["text_array"] = textArray;
                QJsonDocument doc(textObj);
                QByteArray jsonData = doc.toJson(QJsonDocument::Compact);
                //发送并清空之前累计的文本列表
                txt_size = 0;
                textArray = QJsonArray();
                textObj = QJsonObject();
                //发送tcp请求给chat server
                emit tcpMgr::getInstance()->sig_send_data(ReqId::ID_TEXT_CHAT_MSG_REQ, jsonData);
            }

            //将bubble和uid绑定，以后可以等网络返回消息后设置是否送达
            //_bubble_map[uuidString] = pBubble;
            txt_size += msgList[i].content.length();
            QJsonObject obj;
            QByteArray utf8Message = msgList[i].content.toUtf8();
            obj["content"] = QString::fromUtf8(utf8Message);
            obj["msgid"] = uuidString;
            textArray.append(obj);
            auto txt_msg = std::make_shared<TextChatData>(uuidString, obj["content"].toString(),
                                                          user_info->_uid, _user_info->_uid);
            emit sig_append_send_chat_msg(txt_msg);
        }
        else if(type == "image")
        {
            pBubble = new pictureBubble(QPixmap(msgList[i].content) , role);
        }
        else if(type == "file")
        {

        }
        //发送消息
        if(pBubble != nullptr)
        {
            pChatItem->setWidget(pBubble);
            ui->chatDataList->appendChatItem(pChatItem);
        }

    }

    qDebug() << "textArray is " << textArray ;
    //发送给服务器
    textObj["text_array"] = textArray;
    textObj["fromuid"] = user_info->_uid;
    textObj["touid"] = _user_info->_uid;
    QJsonDocument doc(textObj);
    QByteArray jsonData = doc.toJson(QJsonDocument::Compact);
    //发送并清空之前累计的文本列表
    txt_size = 0;
    textArray = QJsonArray();
    textObj = QJsonObject();
    //发送tcp请求给chat server
    emit tcpMgr::getInstance()->sig_send_data(ReqId::ID_TEXT_CHAT_MSG_REQ, jsonData);
}

void chatPage::clearItems()
{
    ui->chatDataList->removeAllItem();
}


void chatPage::on_receiveBtn_clicked()
{
    auto pTextEdit = ui->chatEdit;
    ChatRole role = ChatRole::Other;
    QString userName = _user_info->_name;
    QString userIcon = _user_info->_icon;

    const QVector<MsgInfo>& msgList = pTextEdit->getMsgList();
    for(int i=0; i<msgList.size(); ++i)
    {
        QString type = msgList[i].msgFlag;
        chatItemBase *pChatItem = new chatItemBase(role);
        pChatItem->setUserName(userName);
        pChatItem->setUserIcon(QPixmap(userIcon));
        QWidget *pBubble = nullptr;
        if(type == "text")
        {
            pBubble = new textBubble(role, msgList[i].content);
        }
        else if(type == "image")
        {
            pBubble = new pictureBubble(QPixmap(msgList[i].content) , role);
        }
        else if(type == "file")
        {

        }
        if(pBubble != nullptr)
        {
            pChatItem->setWidget(pBubble);
            ui->chatDataList->appendChatItem(pChatItem);
        }
    }
}

