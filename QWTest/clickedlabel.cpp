#include "clickedlabel.h"

clickedLabel::clickedLabel(QWidget *parent):QLabel (parent),_curstate(ClickLbState::Normal)
{
    this->setCursor(Qt::PointingHandCursor);
}

void clickedLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if(_curstate == ClickLbState::Normal){
            qDebug()<<"clicked , change to selected hover: "<< _selected_press;
            _curstate = ClickLbState::Selected;
            setProperty("state",_selected_press);
            repolish(this);
            //强制刷新效果
            update();
        }else{
            qDebug()<<"clicked , change to normal hover: "<< _normal_press;
            _curstate = ClickLbState::Normal;
            setProperty("state",_normal_press);
            repolish(this);
            update();
        }
        //emit clicked();
        return;
    }
    // 调用基类的mousePressEvent以保证正常的事件处理
    QLabel::mousePressEvent(event);
}

void clickedLabel::enterEvent(QEnterEvent *event)
{
    if(_curstate == ClickLbState::Normal){
        qDebug()<<"enter , change to normal hover: "<< _normal_hover;
        setProperty("state",_normal_hover);
        repolish(this);
        update();
    }else{
        qDebug()<<"enter , change to selected hover: "<< _selected_hover;
        setProperty("state",_selected_hover);
        repolish(this);
        update();
    }
    QLabel::enterEvent(event);
}

void clickedLabel::leaveEvent(QEvent *event)
{
    if(_curstate == ClickLbState::Normal){
        qDebug()<<"leave , change to normal : "<< _normal;
        setProperty("state",_normal);
        repolish(this);
        update();
    }else{
        qDebug()<<"leave , change to normal hover: "<< _selected;
        setProperty("state",_selected);
        repolish(this);
        update();
    }
    QLabel::leaveEvent(event);
}

void clickedLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(_curstate == ClickLbState::Normal){
            qDebug()<<"releaseEvent ,change normal hover"<<_normal_hover;
            setProperty("state",_normal_hover);
            repolish(this);
            update();
        }else{
            qDebug()<<"releaseEvent ,change select hover"<<_selected_hover;
            setProperty("state",_selected_hover);
            repolish(this);
            update();
        }
        emit clicked(this->text(), _curstate);
        return;
    }

    //调用基类处理正常事件
    QLabel::mousePressEvent(event);
}

void clickedLabel::SetState(QString normal, QString hover, QString press, QString select, QString select_hover, QString select_press)
{
    _normal = normal;
    _normal_hover = hover;
    _normal_press = press;

    _selected = select;
    _selected_hover = select_hover;
    _selected_press = select_press;

    setProperty("state",normal);
    repolish(this);
}

ClickLbState clickedLabel::GetCurState()
{
    return _curstate;
}

bool clickedLabel::SetCurState(ClickLbState state)
{
    _curstate = state;
    if (_curstate == ClickLbState::Normal) {
        setProperty("state", _normal);
        repolish(this);
    }
    else if (_curstate == ClickLbState::Selected) {
        setProperty("state", _selected);
        repolish(this);
    }

    return true;
}
void clickedLabel::ResetNormalState()
{
    _curstate = ClickLbState::Normal;
    setProperty("state", _normal);
    repolish(this);
}
