#ifndef CHATVIEW_H
#define CHATVIEW_H
#include <QScrollArea>
#include <QVBoxLayout>
#include <QTimer>

class chatView :public QWidget
{
    Q_OBJECT
public:
    chatView(QWidget *parent = Q_NULLPTR);
    void appendChatItem(QWidget *item);//尾插
    void prependChatItem(QWidget *item);//头插
    void insertChatItem(QWidget *before, QWidget *item);//中间插
    void removeAllItem();
protected:
    bool eventFilter(QObject *o, QEvent *e) override;//事件过滤器
    void paintEvent(QPaintEvent *event) override;//
private slots:
    void onVScrollBarMoved(int min, int max);
private:
    void initStyleSheet();//初始化样式表
    QVBoxLayout *m_pvl;
    QScrollArea *m_pScrollArea;//用垂直布局和SCrollArea来制作聊天记录
    bool isAppended;//防止同时加载
};

#endif // CHATVIEW_H
