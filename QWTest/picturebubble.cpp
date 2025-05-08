#include "picturebubble.h"
#include <QLabel>
#define PIC_MAX_WIDTH 200
#define PIC_MAX_HEIGHT 120
pictureBubble::pictureBubble(const QPixmap &picture, ChatRole role, QWidget *parent):bubbleFrame(role, parent)
{
    QLabel *lb = new QLabel();
    lb->setScaledContents(true);
    QPixmap pix = picture.scaled(QSize(PIC_MAX_WIDTH, PIC_MAX_HEIGHT), Qt::KeepAspectRatio);
    lb->setPixmap(pix);
    this->setWidget(lb);

    int left_margin = this->layout()->contentsMargins().left();
    int right_margin = this->layout()->contentsMargins().right();
    int v_margin = this->layout()->contentsMargins().bottom();
    setFixedSize(pix.width()+left_margin + right_margin, pix.height() + v_margin *2);
}
