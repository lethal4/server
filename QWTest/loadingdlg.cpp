#include "loadingdlg.h"
#include "ui_loadingdlg.h"
#include <QMovie>
loadingDlg::loadingDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loadingDlg)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);//透明背景

    setFixedSize(parent->size());//全屏

    QMovie * movie = new QMovie(":/res/loading.gif");
    ui->loading_lb->setMovie(movie);
    movie->start();
}

loadingDlg::~loadingDlg()
{
    delete ui;
}
