#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpmgr.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginDg = new Login(this);
    loginDg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(loginDg);
    //将login页面放在主页面
    //loginDg->show();
    //创建和连接

    //登录
    connect(loginDg, &Login::switchRegister,this,&MainWindow::slotSwitchReg);

    //重置密码
    connect(loginDg, &Login::switchReset, this, &MainWindow::slotSwitchReset);

    //登录连接
    connect(tcpMgr::getInstance().get(),&tcpMgr::sig_swich_chatdlg, this,&MainWindow::slotSwitchChat);

}

MainWindow::~MainWindow()
{
    delete ui;

    if(loginDg)
    {
        delete loginDg;
        loginDg = nullptr;
    }
    //删除不用的界面
    if(regDg)
    {
        delete regDg;
        regDg = nullptr;
    }
}
void MainWindow::slotSwitchReg()
{
    //动态初始化，点击注册后才切换
    regDg = new registerDialog(this);
    //自定义 CustomizeWindowHint不弹出右上角三个标记

    regDg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    connect(regDg, &registerDialog::sigSwitchLogin, this, &MainWindow::slotSwitchLogin);
    //设置注册对话框
    setCentralWidget(regDg);
    //隐藏login页面
    loginDg->hide();
    regDg->show();
}
void MainWindow::slotSwitchReset()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    resetDg = new ResetDialog(this);
    resetDg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(resetDg);

    loginDg->hide();
    resetDg->show();
    //注册返回登录信号和槽函数
    connect(resetDg, &ResetDialog::switchLogin, this, &MainWindow::slotSwitchLoginTwo);
}
void MainWindow::slotSwitchLogin()
{
    loginDg = new Login(this);
    loginDg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(loginDg);

    regDg->hide();
    loginDg->show();
    //连接登录注册界面信号
    connect(loginDg, &Login::switchRegister, this, &MainWindow::slotSwitchReg);
    //连接登录忘记密码信号
    connect(loginDg, &Login::switchReset,this ,&MainWindow::slotSwitchReset);
    qDebug() << "Switching to login dialog.";

}



void MainWindow::slotSwitchLoginTwo()
{
    loginDg = new Login(this);
    loginDg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(loginDg);

    resetDg->hide();
    loginDg->show();
    //连接登录界面忘记密码信号
    connect(loginDg, &Login::switchReset, this, &MainWindow::slotSwitchReset);
    //连接登录界面注册信号
    connect(loginDg, &Login::switchRegister, this, &MainWindow::slotSwitchReg);
}

void MainWindow::slotSwitchChat()
{
    chatDg = new chatDialog();
    chatDg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(chatDg);
    chatDg->show();
    loginDg->hide();
    this->setMinimumSize(QSize(1300,1000));
    this->setMaximumSize(QWIDGETSIZE_MAX,QWIDGETSIZE_MAX);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mousePressed = true;
        lastMousePos = event->globalPosition().toPoint() - this->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePressed) {
        this->move(event->globalPosition().toPoint() - lastMousePos);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mousePressed = false;
    }
}
