#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include "httpmanager.h"
registerDialog::registerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerDialog),_countdown(3)
{
    ui->setupUi(this);

    //设置密码保密模式
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->passwordTwoEdit->setEchoMode(QLineEdit::Password);

    //告诉QT有一个状态为normal
    ui->errTip->setProperty("state","normal");
    //global中定义的刷新使用
    repolish(ui->errTip);

    connect(httpManager::getInstance().get(),&httpManager::signRegModFinish,this,&registerDialog::slotRegModFinish);

    initHttpHandlers();

    ui->errTip->clear();

    connect(ui->userEdit,&QLineEdit::editingFinished,this,[this](){
        checkUserValid();
    });
    connect(ui->emailEdit, &QLineEdit::editingFinished, this, [this](){
        checkEmailValid();
    });
    connect(ui->passwordEdit, &QLineEdit::editingFinished, this, [this](){
        checkPassValid();
    });
    connect(ui->passwordTwoEdit, &QLineEdit::editingFinished, this, [this](){
        checkConfirmValid();
    });
    connect(ui->varifyEdit, &QLineEdit::editingFinished, this, [this](){
        checkVarifyValid();
    });

    ui->passwordVisble->setCursor(Qt::PointingHandCursor);
    ui->passwordTwoVisble->setCursor(Qt::PointingHandCursor);

    ui->passwordVisble->SetState("unvisible","unvisible_hover","","visible","visible_hover","");
    ui->passwordTwoVisble->SetState("unvisible","unvisible_hover","","visible","visible_hover","");



    connect(ui->passwordVisble, &clickedLabel::clicked, this ,[this](){
        auto state = ui->passwordVisble->GetCurState();
        if( state == ClickLbState::Normal)
        {
            ui->passwordEdit->setEchoMode(QLineEdit::Password);
        }
        else
        {
            ui->passwordEdit->setEchoMode(QLineEdit::Normal);
        }
    });
    connect(ui->passwordTwoVisble, &clickedLabel::clicked, this ,[this](){//统一信号和槽
        auto state = ui->passwordTwoVisble->GetCurState();
        if( state == ClickLbState::Normal)
        {
            ui->passwordTwoEdit->setEchoMode(QLineEdit::Password);
        }
        else
        {
            ui->passwordTwoEdit->setEchoMode(QLineEdit::Normal);
        }
    });

    //创建一个定时器用于注册后回到登录界面
    _countdown_timer = new QTimer(this);
    connect(_countdown_timer, &QTimer::timeout,this,[this](){
        if(_countdown == 0){
            _countdown_timer->stop();
            emit sigSwitchLogin();
            return ;
        }
        _countdown--;
        auto str = QString("注册成功， %1秒后返回登录页面").arg(_countdown);
        ui->tipLabelOne->setText(str);//修改弹窗文字
    });
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::on_getCode_clicked()
{
    auto email = ui->emailEdit->text();
    //正则表达式创建并对比对比
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.)(\w+)+)");
    bool match = regex.match(email).hasMatch();
    if(match)
    {
        //发送验证码
        QJsonObject json_obj;
        json_obj["email"]=email;
        httpManager::getInstance()->postHttpReq(QUrl(gate_url_prefix +"/get_varifycode"),
                                                json_obj, ReqId::ID_GET_VARIFY_CODE, Modules::REGISTERMOD);
    }
    else
    {
        showTip(tr("邮箱地址不正确"),false);
    }
}

void registerDialog::slotRegModFinish(ReqId id, QString res ,ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS)
    {
       showTip(tr("网络请求错误"),false);
        return ;
    }
    //解析json 字符串 ，res 转换成QByteArray;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());

    //判断js是否为空
    if(jsonDoc.isNull())
    {
        showTip(tr("json解析失败"),false);
        return;
    }
    //解析成功但是解析的不是json对象
    if(!jsonDoc.isObject())
    {
        //转换失败
        showTip(tr("json解析失败"),false);
        return ;
    }

    //转换成功
    //返回的函数对象可以直接使用
    handlers[id](jsonDoc.object());
    return ;
}
void registerDialog::showTip(QString str,bool isOk)
{

    if(isOk)
    {
        //更改样式状态
        ui->errTip->setProperty("state","normal");
        ui->errTip->setText(str);
        //突然发现这里没有添加settext，11/10加上的
    }
    else
    {
        //更改样式状态
        ui->errTip->setProperty("state","err");
        //把错误信息打印到errTip上
        ui->errTip->setText(str);
    }



    repolish(ui->errTip);
}

void registerDialog::initHttpHandlers()
{
    //注册获取验证码回包逻辑
    handlers.insert(ReqId::ID_GET_VARIFY_CODE, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已发送到邮箱，注意查收"), true);
        qDebug()<< "email is " << email ;
    });

    //注册注册用户回包逻辑
    handlers.insert(ReqId::ID_REG_USER, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("用户注册成功"), true);
        qDebug()<< "email is " << email ;
        qDebug()<< "user uuid is " <<  jsonObj["uid"].toString();
        changeTipPage();
    });
}

void registerDialog::addTipErr(TipErr te,QString tips)
{
    tipErrs[te]= tips;
    showTip(tips,false);
}
void registerDialog::delTipErr(TipErr te)
{
    tipErrs.remove(te);
    if(tipErrs.empty())
    {
        ui->errTip->clear();
        return;
    }
}
bool registerDialog::checkUserValid()
{
    if(ui->userEdit->text() == ""){
        addTipErr(TipErr::TIP_USER_ERR, tr("用户名不可为空"));
        return false;
    }
    delTipErr(TipErr::TIP_USER_ERR);
    return true;
}

bool registerDialog::checkEmailValid()
{
    auto email = ui->emailEdit->text();
    // 邮箱正则表达式
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch(); // 正则表达式匹配
    if(!match){
        //邮箱不正确
        addTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱地址不正确"));
        return false;
    }
    delTipErr(TipErr::TIP_EMAIL_ERR);
    return true;
}

bool registerDialog::checkPassValid()
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

bool registerDialog::checkConfirmValid()
{
    auto pass = ui->passwordEdit->text();
    auto confirm = ui->passwordTwoEdit->text();

    if(confirm.length() < 6 || confirm.length() > 15 ){
        //长度不准确
        addTipErr(TipErr::TIP_CONFIRM_ERR, tr("密码长度应为6~15"));
        return false;
    }
    //同上
    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*.]{6,15}$");
    bool match = regExp.match(confirm).hasMatch();
    if(!match){
        addTipErr(TipErr::TIP_CONFIRM_ERR, tr("不能包含非法字符"));
        return false;
    }

    delTipErr(TipErr::TIP_CONFIRM_ERR);

    if(pass != confirm){
        //提示密码不匹配
        addTipErr(TipErr::TIP_PWD_CONFIRM, tr("确认密码和密码不匹配"));
        return false;
    }else{
        delTipErr(TipErr::TIP_PWD_CONFIRM);
    }
    return true;
}

bool registerDialog::checkVarifyValid()
{
    auto pass = ui->varifyEdit->text();
    if(pass.isEmpty()){
        addTipErr(TipErr::TIP_VARIFY_ERR, tr("验证码不能为空"));
        return false;
    }
    delTipErr(TipErr::TIP_VARIFY_ERR);
    return true;
}

void registerDialog::changeTipPage()
{
    _countdown_timer->stop();
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    //启动定时器
    _countdown_timer->start(1000);
}


void registerDialog::on_sureButton_clicked()
{
    /*if (ui->userEdit->text() == ""){
        showTip(tr("用户名不可为空"),false);
        return;
    }
    if (ui->emailEdit->text() == ""){
        showTip(tr("邮箱地址不可为空"),false);
        return;
    }
    if(ui->passwordEdit->text() == ""){
        showTip(tr("密码不可为空"),false);
        return;
    }
    if(ui->passwordTwoEdit->text() == ""){
        showTip(tr("确认密码不能为空"), false);
        return;
    }
    if(ui->passwordEdit->text() != ui->passwordTwoEdit->text()){
        showTip(tr("密码和确认密码不匹配"), false);
        return;
    }

    if(ui->varifyEdit->text() == ""){
        showTip(tr("验证码不能为空"), false);
        return;
    }*/
    bool valid = checkUserValid();
    if(!valid){
        return;
    }
    valid = checkEmailValid();
    if(!valid){
        return;
    }
    valid = checkPassValid();
    if(!valid){
        return;
    }
    valid = checkVarifyValid();
    if(!valid){
        return;
    }

    //发送http请求注册
    QJsonObject jsonObj;
    jsonObj["user"] = ui->userEdit->text();
    jsonObj["email"] = ui->emailEdit->text();
    jsonObj["passwd"] = ui->passwordEdit->text();
    jsonObj["varifycode"] = ui->varifyEdit->text();
    jsonObj["confirm"] = ui->passwordTwoEdit->text();

    httpManager::getInstance()->postHttpReq(QUrl(gate_url_prefix+"/user_register"),jsonObj, ReqId::ID_REG_USER,Modules::REGISTERMOD);
}



void registerDialog::on_returnButton_clicked()
{
    _countdown_timer->stop();
    emit sigSwitchLogin();
}


void registerDialog::on_cancelButton_clicked()
{
    _countdown_timer->stop();
    emit sigSwitchLogin();
}

