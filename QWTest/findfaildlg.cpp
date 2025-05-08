#include "findfaildlg.h"
#include "ui_findfaildlg.h"
#include <QDir>
findFailDlg::findFailDlg(QWidget *parent)
    : QDialog(parent),_parent(parent)
    , ui(new Ui::findFailDlg)
{
    ui->setupUi(this);
    setWindowTitle("添加");
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);// 隐藏对话框标题栏
    this->setObjectName("FindFailDlg");
    ui->fail_sure_btn->SetState("normal","hover","press");
    this->setModal(true);//模态
}

findFailDlg::~findFailDlg()
{
    qDebug()<<"findFailDlg destruct";
    delete ui;
}

void findFailDlg::on_fail_sure_btn_clicked()
{
    this->hide();
}
