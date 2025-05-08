#ifndef CHATPAGE_H
#define CHATPAGE_H

#include <QWidget>
#include <QMap>
#include "userdata.h"
namespace Ui {
class chatPage;
}

class chatPage : public QWidget
{
    Q_OBJECT

public:
    explicit chatPage(QWidget *parent = nullptr);
    ~chatPage();

    void SetUserInfo(std::shared_ptr<UserInfo> user_info);
    void AppendChatMsg(std::shared_ptr<TextChatData> msg);
protected:
    void paintEvent(QPaintEvent * event);//重写QWidget

private slots:
    void on_sendBtn_clicked();
    void on_receiveBtn_clicked();

private:
    Ui::chatPage *ui;
    void clearItems();
    std::shared_ptr<UserInfo> _user_info;
    QMap<QString, QWidget*>  _bubble_map;
signals:
    void sig_append_send_chat_msg(std::shared_ptr<TextChatData> msg);
};

#endif // CHATPAGE_H
