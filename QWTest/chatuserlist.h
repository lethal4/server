#ifndef CHATUSERLIST_H
#define CHATUSERLIST_H
#include <QListWidget>
#include <QEvent>
#include <QScrollBar>
#include <QDebug>
class chatUserList:public QListWidget
{
    Q_OBJECT
public:
    chatUserList(QWidget *parent);
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;//自定义
private:
    bool _load_pending;
signals:
    void sig_loading_chat_user();
};

#endif // CHATUSERLIST_H
