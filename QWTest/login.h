#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "global.h"
#include "httpmanager.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    int _uid;
    QString _token;

    Ui::Login *ui;
    void initHead();
    bool checkUserValid();
    void addTipErr(TipErr te,QString tips);
    void delTipErr(TipErr te);
    QMap<TipErr,QString> _tip_errs;
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;
    void showTip(QString str, bool b_ok);
    bool checkPassValid();
    bool enableBtn(bool enabled);
    void initHttpHandlers();
    //定义信号
public slots://槽函数
    void slot_forget_pwd();
signals:
    void switchRegister();
    void switchReset();
    void sig_connect_tcp(ServerInfo);//中转信号，发送给TCP长连接

private slots://函数可以直接连接到信号（signals），即使它们是私有的。信号发出时，Qt 的信号与槽机制会自动调用这些私有槽函数。
    void on_loginButton_clicked();
    void slot_login_mod_finish(ReqId id,QString res,ErrorCodes err);
    void slot_tcp_con_finish(bool bsuccess);
    void slot_login_failed(int);
};

#endif // LOGIN_H
