#include "timebtn.h"
#include <QMouseEvent>
#include <QDebug>
timeBtn::timeBtn(QWidget *parent):QPushButton(parent),_counter(10)
{
    _timer = new QTimer(this);//timeBtn被回收同时回收_timer

    connect(_timer, &QTimer::timeout, [this](){
        _counter--;
        if(_counter<=0)
        {
            _timer->stop();
            _counter=10;
            this->setText("获取");
            this->setEnabled(true);
            return;
        }
        this->setText(QString::number(_counter));
    });
}

timeBtn::~timeBtn()
{
    _timer->stop();
}

void timeBtn::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        // 处理鼠标左键释放事件
        qDebug() <<"myButton was Released.";
        this->setEnabled(false);//按钮不可用
        this->setText(QString::number(_counter));
        _timer->start(1000);
        emit clicked();//高版本可能不需要这一行
    }

    //调用积累的mouseReleaseEvent 确保正常的事件处理；
    QPushButton::mouseReleaseEvent(e);
}
