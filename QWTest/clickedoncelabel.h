#ifndef CLICKEDONCELABEL_H
#define CLICKEDONCELABEL_H

#include <QLabel>
#include <QMouseEvent>
class clickedOnceLabel : public QLabel
{
    Q_OBJECT
public:
    clickedOnceLabel(QWidget *parent=nullptr);
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void clicked(QString );

};

#endif // CLICKEDONCELABEL_H
