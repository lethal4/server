#ifndef CHATITEMBASE_H
#define CHATITEMBASE_H
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "global.h"
class chatItemBase: public QWidget
{
    Q_OBJECT
public:
    explicit chatItemBase(ChatRole role, QWidget *parent = nullptr);
    void setUserName(const QString &name);
    void setUserIcon(const QPixmap &icon);
    void setWidget(QWidget *w);

private:
    ChatRole mRole;
    QLabel *mNameLabel;
    QLabel *mIconLabel;
    QWidget *mBubble;//气泡
};
#endif // CHATITEMBASE_H
