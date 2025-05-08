#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H
#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

//继承获得信号和槽
//CRTP 继承自己
class httpManager:public QObject,public singleton<httpManager>,public std::enable_shared_from_this<httpManager>
{
    Q_OBJECT
public:
    /*
    instance是singleton的成员,C++规则在析构时候会回收自己的成员变量,
    instance的析构为智能指针的析构,根据模板化所以调用T,T为httpManager的析构
    所以httpManager的析构必须为公有
    */
    ~httpManager();
    void postHttpReq(QUrl url,QJsonObject json ,ReqId reqId,Modules mod);
private:

    //将基类设置为自己的友元使得基类可以访问自己的构造函数
    friend class singleton<httpManager>;
    httpManager();
    //定义qt原生http网络管理者
    QNetworkAccessManager qManager;
    //发送函数 路由QUrl js数据 模块id 模块
    //qt发送为同步和异步,主要为异步,回调时间不确定

//槽函数在信号函数上面写 槽函数的参数不可多余信号函数的参数
private slots:
    void slotHttpFinish(ReqId id , QString res , ErrorCodes err , Modules mod);
signals:
        //请求ID 结果 具体错误 属于哪个模块
    void signHttpFinish(ReqId id , QString res , ErrorCodes err , Modules mod);
    void signRegModFinish(ReqId id, QString res ,ErrorCodes err);
    void signResetModFinish(ReqId id, QString res,ErrorCodes err);
    void sigLoginModFinish(ReqId id, QString res,ErrorCodes err);
};

#endif // HTTPMANAGER_H
