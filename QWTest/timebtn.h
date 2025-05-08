#ifndef TIMEBTN_H
#define TIMEBTN_H
#include <QPushButton>
#include <QTimer>
class timeBtn:public QPushButton
{
public:
    timeBtn(QWidget *parent = nullptr);
    ~timeBtn();
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
private :
    QTimer  *_timer;
    int _counter;
};

#endif // TIMEBTN_H
