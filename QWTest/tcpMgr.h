#ifndef TCPMGR_H
#define TCPMGR_H
#include <QTcpSocket>
#include "singleton.h"
#include "global.h"
#include <functional>
#include <QObject>
#include "userdata.h"
                    //收发信号       单例模板           生成管理智能指针
class tcpMgr:public QObject, public singleton<tcpMgr>,public std::enable_shared_from_this<tcpMgr>
{
    Q_OBJECT
public:
    ~tcpMgr();
private:
    tcpMgr();
    friend class singleton<tcpMgr>;
    void initHandlers();//回调处理
    void handleMsg(ReqId id, int len, QByteArray data);
    QTcpSocket _socket;
    QString _host;
    uint16_t _port;
    QByteArray _buffer;//缓存 TCP面向字节流
    bool _b_recv_pending;//防止没有收全数据，做一个判定
    quint16 _message_id;
    quint16 _message_len;
    QMap<ReqId, std::function<void(ReqId id, int len, QByteArray data)>> _handlers;
public slots:
    void slotTcpConnect(ServerInfo);
    void slotSendData(ReqId reqId, QByteArray data);
signals:
    void sig_con_success(bool bsuccess);
    void sig_send_data(ReqId reqId, QByteArray data);
    void sig_swich_chatdlg();
    void sig_login_failed(int);
    void sig_user_search(std::shared_ptr<searchInfo>);
    void sig_friend_apply(std::shared_ptr<AddFriendApply>);
    void sig_add_auth_friend(std::shared_ptr<AuthInfo>);
    void sig_auth_rsp(std::shared_ptr<AuthRsp>);
    void sig_text_chat_msg(std::shared_ptr<TextChatMsg> msg);
};

#endif // TCPMGR_H
