#ifndef BUBBLEFRAME_H
#define BUBBLEFRAME_H
#include <QFrame>
#include <global.h>
#include <QHBoxLayout>
class bubbleFrame : public QFrame
{
    Q_OBJECT
public:
    bubbleFrame(ChatRole role, QWidget *parent = nullptr);
    void setMargin(int margin);
    void setWidget(QWidget *w);
protected:
    void paintEvent(QPaintEvent *e);
private:
    QHBoxLayout *m_pHLayout;
    ChatRole m_role;
    int      m_margin;
};

#endif // BUBBLEFRAME_H
