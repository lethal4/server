#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"
namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = nullptr);
    ~registerDialog();

private slots:
    void on_getCode_clicked();
    void slotRegModFinish(ReqId id, QString res ,ErrorCodes err);
    void on_sureButton_clicked();

    void on_cancelButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::registerDialog *ui;
    void showTip(QString str,bool isOk);
    void initHttpHandlers();
    bool checkUserValid();
    bool checkEmailValid();
    bool checkPassValid();
    bool checkConfirmValid();
    bool checkVarifyValid();
    void changeTipPage();
    void addTipErr(TipErr te,QString tips);
    void delTipErr(TipErr te);
    //用handler
    QMap<ReqId, std::function<void(const QJsonObject&)>>handlers;
    QMap<TipErr, QString>tipErrs;

    QTimer * _countdown_timer;
    int _countdown;

signals:
    void sigSwitchLogin();
};

#endif // REGISTERDIALOG_H
