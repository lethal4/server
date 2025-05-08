#include "login.h"
#include "httpmanager.h"
#include "ui_login.h"
#include <QPainter>
#include <QPainterPath>
#include "tcpmgr.h"
Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->regButton,&QPushButton::clicked,this,&Login::switchRegister);
    //连接按钮
    //触发为clicked而不是click
    ui->forgetLabel->SetState("normal","hover","","selected","selected_hover","");
    ui->passwdvisit->SetState("unvisible","unvisible_hover","","visible","visible_hover","");
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    connect(ui->passwdvisit, &clickedLabel::clicked, this ,[this](){//统一信号和槽
        auto state = ui->passwdvisit->GetCurState();
        if( state == ClickLbState::Normal)
        {
            ui->passwordEdit->setEchoMode(QLineEdit::Password);
        }
        else
        {
            ui->passwordEdit->setEchoMode(QLineEdit::Normal);
        }
    });


    connect(ui->forgetLabel, &clickedLabel::clicked, this , &Login::slot_forget_pwd);

    initHead();//登录页面的背景图片操作
    initHttpHandlers();

    //连接登录回包信号
    connect(httpManager::getInstance().get(),&httpManager::sigLoginModFinish, this,&Login::slot_login_mod_finish);
    //连接TCP请求信号和槽函数
    connect(this, &Login::sig_connect_tcp, tcpMgr::getInstance().get(), &tcpMgr::slotTcpConnect);
    //连接tcp管理者发出的连接成功信号
    connect(tcpMgr::getInstance().get(), &tcpMgr::sig_con_success, this , &Login::slot_tcp_con_finish);
    //连接TCP管理者发送连接失败的信号
    connect(tcpMgr::getInstance().get(), &tcpMgr::sig_login_failed, this , &Login::slot_login_failed);

}

Login::~Login()
{
    delete ui;
}

void Login::initHead()
{
    // 加载图片
    QPixmap originalPixmap(":/res/login.jpg");
    // 设置图片自动缩放
    qDebug()<< originalPixmap.size() << ui->headLabel->size();
    originalPixmap = originalPixmap.scaled(ui->headLabel->size(),
                                           Qt::KeepAspectRatio, Qt::SmoothTransformation);
                                            //等比例              平滑

    // 获取图片的宽度和高度（假设是正方形）
    int size = qMin(originalPixmap.width(), originalPixmap.height());

    // 创建一个和原始图片相同大小的QPixmap，用于绘制圆形图片
    QPixmap circularPixmap(size, size);
    circularPixmap.fill(Qt::transparent); // 用透明色填充

    // 创建QPainter进行绘制
    QPainter painter(&circularPixmap);
    painter.setRenderHint(QPainter::Antialiasing); // 设置抗锯齿，使圆形更平滑
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    // 使用QPainterPath设置圆形
    QPainterPath path;
    path.addEllipse(0, 0, size, size); // 使用圆形路径，宽高都为图片的边长
    painter.setClipPath(path);

    // 将原始图片绘制到圆形路径内
    painter.drawPixmap(0, 0, originalPixmap.scaled(size, size, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 设置绘制好的圆形图片到QLabel上
    ui->headLabel->setPixmap(circularPixmap);

}

bool Login::checkUserValid()
{
    auto email = ui->userEdit->text();
    if(email.isEmpty())
    {
        qDebug()<<"email is empty";
        addTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱不可为空"));
        return false;
    }
    delTipErr(TipErr::TIP_EMAIL_ERR);
    return true;
}

void Login::addTipErr(TipErr te, QString tips)
{
    _tip_errs[te] = tips;
    showTip(tips, false);
}

void Login::delTipErr(TipErr te)
{
    _tip_errs.remove(te);
    if(_tip_errs.empty()){
        ui->errTip->clear();
        return;
    }
    showTip(_tip_errs.first(),false);
}

void Login::showTip(QString str, bool b_ok)
{
    if(b_ok){
        ui->errTip->setProperty("state","normal");
    }
    else {
        ui->errTip->setProperty("state","err");
    }
    ui->errTip->setText(str);

    repolish(ui->errTip);//更新样式
}

void Login::slot_forget_pwd()
{
    qDebug()<<"slot forget password";
    emit switchReset();
}

void Login::on_loginButton_clicked()
{
    qDebug()<<"loginButton clicked";
    if(checkUserValid()==false){
        return;
    }
    if(checkPassValid()==false){
        return;
    }
    enableBtn(false);
    //按钮变为不可用
    auto email = ui->userEdit->text();
    auto password = ui->passwordEdit->text();

    QJsonObject json_obj;
    json_obj["email"] = email;
    json_obj["passwd"] = password;
    httpManager::getInstance()->postHttpReq(QUrl(gate_url_prefix+"/user_login"),
                                            json_obj,ReqId::ID_LOGIN_USER,Modules::LOGINMOD);
}

void Login::slot_login_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"),false);
        enableBtn(true);
        return;
    }

    // 解析 JSON 字符串,res需转化为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    //json解析错误
    if(jsonDoc.isNull()){
        showTip(tr("json解析错误null"),false);
        return;
    }

    //json解析错误
    if(!jsonDoc.isObject()){
        showTip(tr("json解析错误isobject"),false);
        return;
    }


    //调用对应的逻辑,根据id回调。
    _handlers[id](jsonDoc.object());

    return;
}

void Login::slot_tcp_con_finish(bool bsuccess)
{
    if(bsuccess){
        showTip(tr("聊天服务连接成功，正在登录..."),true);
        QJsonObject jsonObj;
        jsonObj["uid"] = _uid;
        jsonObj["token"] = _token;


        QJsonDocument doc(jsonObj);
        QByteArray jsonData = doc.toJson(QJsonDocument::Indented);

        //发送tcp请求给chat server
        emit tcpMgr::getInstance()->sig_send_data(ReqId::ID_CHAT_LOGIN, jsonData);

    }else{
        showTip(tr("网络异常"),false);
        enableBtn(true);
    }
}

void Login::slot_login_failed(int err)
{
    QString result = QString("登录失败, err is %1")
                         .arg(err);
    showTip(result,false);
    enableBtn(true);
}

bool Login::checkPassValid()
{
    auto pass = ui->passwordEdit->text();
    if(pass.length() < 6 || pass.length()>15){
        //长度不准确
        addTipErr(TipErr::TIP_PWD_ERR, tr("密码长度应为6~15"));
        return false;
    }
    // ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(pass).hasMatch();
    if(!match){
        //字符非法
        addTipErr(TipErr::TIP_PWD_ERR, tr("不能包含非法字符"));
        return false;
    }
    delTipErr(TipErr::TIP_PWD_ERR);
    return true;
}

bool Login::enableBtn(bool enabled)
{
    ui->loginButton->setEnabled(enabled);
    ui->regButton->setEnabled(false);
    return true;
}

void Login::initHttpHandlers()
{
    _handlers.insert(ReqId::ID_LOGIN_USER, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error !=ErrorCodes::SUCCESS){
            showTip(tr("参数错误: ") + QString::number(error), false);


            qDebug() << "Login Error: " << error;
            qDebug() << "Full jsonObj: " << jsonObj;

            // 输出每个字段的具体内容
            if (jsonObj.contains("error")) {
                qDebug() << "Error field: " << jsonObj["error"].toInt();
            }
            if (jsonObj.contains("email")) {
                qDebug() << "Email field: " << jsonObj["email"].toString();
            }
            if (jsonObj.contains("uid")) {
                qDebug() << "UID field: " << jsonObj["uid"].toInt();
            }
            if (jsonObj.contains("host")) {
                qDebug() << "Host field: " << jsonObj["host"].toString();
            }
            if (jsonObj.contains("port")) {
                qDebug() << "Port field: " << jsonObj["port"].toString();
            }
            if (jsonObj.contains("token")) {
                qDebug() << "Token field: " << jsonObj["token"].toString();
            }


            enableBtn(true);
            return;
        }
        auto email = jsonObj["email"].toString();

        //发送信息通知给tcpManager长连接
        ServerInfo si;
        si.Uid = jsonObj["uid"].toInt();
        si.Host = jsonObj["host"].toString();
        si.Port = jsonObj["port"].toString();
        si.Token = jsonObj["token"].toString();

        showTip(tr("登录成功"), true);
        _uid = si.Uid;
        _token = si.Token;
        qDebug()<< "email is " << email << " uid is " << si.Uid <<" host is "
                 << si.Host << " Port is " << si.Port << " Token is " << si.Token;
        emit sig_connect_tcp(si);//tcp管理者，队列
    });


}

