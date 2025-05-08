#ifndef SEARCHLIST_H
#define SEARCHLIST_H
#include <QListWidget>
#include <QWheelEvent>
#include <QEvent>
#include <QScrollBar>
#include <QDebug>
#include <QDialog>
#include <memory>
#include "loadingdlg.h"
#include "userdata.h"
class searchList :public QListWidget
{
    Q_OBJECT
public:
    searchList(QWidget *parent = nullptr);
    void closeFindDlg();
    void setSearchEdit(QWidget* edit);
protected:
    bool eventFilter(QObject *watched, QEvent *event) override ;
private:
    void waitPending(bool pending = true);
    bool _send_pending;
    void addTipItem();
    std::shared_ptr<QDialog> _find_dg;
    QWidget* _search_edit;
    loadingDlg * _loadingDialog;
private slots:
    void slot_item_clicked(QListWidgetItem *item);
    void slot_user_search(std::shared_ptr<searchInfo> si);
signals:
    void sig_jump_chat_item(std::shared_ptr<searchInfo> si);
};

#endif // SEARCHLIST_H
