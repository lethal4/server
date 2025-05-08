#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "registerdialog.h"
#include "resetdialog.h"
#include "chatdialog.h"
#include <QPushButton>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void slotSwitchReg();
    void slotSwitchLogin();
    void slotSwitchReset();
    void slotSwitchLoginTwo();
    void slotSwitchChat();


private:
    Ui::MainWindow *ui;

    bool mousePressed;
    QPoint lastMousePos;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    Login * loginDg;
    registerDialog * regDg;
    ResetDialog * resetDg;
    chatDialog * chatDg;

};
#endif // MAINWINDOW_H
