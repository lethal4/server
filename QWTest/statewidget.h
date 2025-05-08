#ifndef STATEWIDGET_H
#define STATEWIDGET_H
#include <QWidget>
#include <QLabel>
#include "global.h"
class stateWidget :public QWidget
{
    Q_OBJECT
public:
    explicit stateWidget(QWidget *parent = nullptr);

    void setState(QString normal="", QString hover="", QString press="",QString select="", QString select_hover="", QString select_press="");

    ClickLbState getCurState();
    void clearState();

    void setSelected(bool bselected);
    void addRedPoint();
    void showRedPoint(bool show);

protected:
    void paintEvent(QPaintEvent* event);

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEnterEvent* event) override;
    virtual void leaveEvent(QEvent* event) override;

private:

    QString _normal;
    QString _normal_hover;
    QString _normal_press;

    QString _selected;
    QString _selected_hover;
    QString _selected_press;

    ClickLbState _curstate;
    QLabel * _red_point;

signals:
    void clicked(void);

signals:

public slots:
};

#endif // STATEWIDGET_H
