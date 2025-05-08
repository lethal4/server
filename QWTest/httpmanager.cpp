#include "httpmanager.h"

httpManager::~httpManager()
{

}

httpManager::httpManager()
{
    //连接信号和槽函数
    connect(this,&httpManager::signHttpFinish,this,&httpManager::slotHttpFinish);
}


void httpManager::postHttpReq(QUrl url,QJsonObject json ,ReqId reqId,Modules mod)
{   //底层发送都为字节
    QByteArray data = QJsonDocument(json).toJson();
    //构造url
    QNetworkRequest request(url);
    //http 基于tcp 对方回答之后就断开
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));
    //闭包技术 shared_from_this是通过http自己指针生成的智能指针
    auto self = shared_from_this();
    //发送完请求会受到回应
    QNetworkReply * reply = qManager.post(request , data);

    //发送完毕之后检测回收
    connect(reply,&QNetworkReply::finished,[self,reply,reqId,mod](){
    //                                      this在回调触发之前不能被删除，所以捕获self
        if(reply->error()!=QNetworkReply::NoError)
        {
        //存在错误
            qDebug()<< reply->errorString();
        //通知到其他部件
            emit self->signHttpFinish(reqId,"",ErrorCodes::ERR_NETWORK,mod);
            //告诉Qt不用的时候回收reply
            reply->deleteLater();
            return;
        }

        //无错误 则读出所有的字节转成QString
        QString res = reply->readAll();
        //发送到其他部件通知完成
        emit self->signHttpFinish(reqId , res , ErrorCodes::SUCCESS,mod);
        reply->deleteLater();
        return ;
    });//lambda表达式
}

void httpManager::slotHttpFinish(ReqId id , QString res , ErrorCodes err , Modules mod){
    if (mod == Modules::REGISTERMOD)
    {
        //注册模块的信号
        //发送信号通知指定的http模块响应结束了
        emit signRegModFinish(id,res,err);
    }

    if(mod == Modules::RESETMOD)
    {
        //重置密码
        emit signResetModFinish(id,res,err);
    }

    if(mod == Modules::LOGINMOD){
        //登录
        emit sigLoginModFinish(id,res,err);
    }
}
