#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QLabel>
#include "global.h"
#include <QMouseEvent>
class clickedLabel : public QLabel
{
    Q_OBJECT
public:
    clickedLabel(QWidget *parent=nullptr);
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEnterEvent* event) override;//QT6中将QEvent改为QEnterEvent
    virtual void leaveEvent(QEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    void SetState(QString normal="", QString hover="", QString press="",
                  QString select="", QString select_hover="", QString select_press="");

    ClickLbState GetCurState();
    bool SetCurState(ClickLbState state);
    void ResetNormalState();
protected:

private:
    QString _normal;
    QString _normal_hover;
    QString _normal_press;

    QString _selected;
    QString _selected_hover;
    QString _selected_press;

    ClickLbState _curstate;
signals:
    void clicked(QString, ClickLbState);

};

#endif // CLICKEDLABEL_H
