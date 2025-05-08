#ifndef PICTUREBUBBLE_H
#define PICTUREBUBBLE_H
#include "bubbleFrame.h"
#include <QHBoxLayout>
#include <QPixmap>
class pictureBubble :public bubbleFrame
{
    Q_OBJECT
public:
    pictureBubble(const QPixmap &picture, ChatRole role, QWidget *parent = nullptr);

};

#endif // PICTUREBUBBLE_H
