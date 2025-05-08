#include "clickbtn.h"
#include "global.h"

clickBtn::clickBtn(QWidget *parent):QPushButton (parent)
{
    setCursor(Qt::PointingHandCursor); // 设置光标为小手
    setFocusPolicy(Qt::NoFocus);

}

clickBtn::~clickBtn(){

}

void clickBtn::SetState(QString normal, QString hover, QString press)
{
    _hover = hover;
    _normal = normal;
    _press = press;
    setProperty("state",normal);
    repolish(this);
    update();
}

void clickBtn::enterEvent(QEnterEvent *event)
{
    setProperty("state",_hover);
    repolish(this);
    update();
    QPushButton::enterEvent(event);
}

void clickBtn::leaveEvent(QEvent *event)
{
    setProperty("state",_normal);
    repolish(this);
    update();
    QPushButton::leaveEvent(event);
}

void clickBtn::mousePressEvent(QMouseEvent *event)
{
    setProperty("state",_press);
    repolish(this);
    update();
    QPushButton::mousePressEvent(event);
}

void clickBtn::mouseReleaseEvent(QMouseEvent *event)
{
    setProperty("state",_hover);
    repolish(this);
    update();
    QPushButton::mouseReleaseEvent(event);
}
