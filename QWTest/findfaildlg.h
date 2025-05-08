#ifndef FINDFAILDLG_H
#define FINDFAILDLG_H

#include <QDialog>
#include "userdata.h"
namespace Ui {
class findFailDlg;
}

class findFailDlg : public QDialog
{
    Q_OBJECT

public:
    explicit findFailDlg(QWidget *parent = nullptr);
    ~findFailDlg();

private:
    Ui::findFailDlg *ui;
    std::shared_ptr<searchInfo> _si;
    QWidget * _parent;
private slots:
    void on_fail_sure_btn_clicked();
};

#endif // FINDFAILDLG_H
