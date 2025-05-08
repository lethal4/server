#ifndef FINDSUCCESSDG_H
#define FINDSUCCESSDG_H

#include <QDialog>
#include <memory>
#include "userdata.h"
namespace Ui {
class findSuccessDg;
}

class findSuccessDg : public QDialog
{
    Q_OBJECT

public:
    explicit findSuccessDg(QWidget *parent = nullptr);
    ~findSuccessDg();
    void setSearchInfo(std::shared_ptr<searchInfo> si);//搜索用户信息
private:
    std::shared_ptr<searchInfo> _si;
    QWidget * _parent;
    Ui::findSuccessDg *ui;
private slots:
    void on_add_friend_btn_clicked();
signals:
};

#endif // FINDSUCCESSDG_H
