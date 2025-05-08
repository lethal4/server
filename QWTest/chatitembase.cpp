#include "chatitembase.h"
#include <QPainter>
chatItemBase::chatItemBase(ChatRole role, QWidget *parent):  QWidget(parent), mRole(role)
{
    mNameLabel = new QLabel();
    mNameLabel->setObjectName("chat_user_name");
    QFont font("Microsoft YaHei");
    font.setPointSize(9);
    mNameLabel->setFont(font);
    mNameLabel->setFixedHeight(20);

    mIconLabel    = new QLabel();
    mIconLabel->setScaledContents(true);
    mIconLabel->setFixedSize(42, 42);

    mBubble       = new QWidget();

    QGridLayout *pGLayout = new QGridLayout();
    pGLayout->setVerticalSpacing(3);//竖向间距
    pGLayout->setHorizontalSpacing(3);//横向间距
    pGLayout->setContentsMargins(3,3,3,3);

    QSpacerItem*pSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    if(mRole == ChatRole::Self)//自己的
    {
        mNameLabel->setContentsMargins(0,0,8,0);
        mNameLabel->setAlignment(Qt::AlignRight);
        pGLayout->addWidget(mNameLabel, 0,1, 1,1);
        pGLayout->addWidget(mIconLabel, 0, 2, 2,1, Qt::AlignTop);
        pGLayout->addItem(pSpacer, 1, 0, 1, 1);
        pGLayout->addWidget(mBubble, 1,1, 1,1);
        pGLayout->setColumnStretch(0, 2);
        pGLayout->setColumnStretch(1, 3);
    }else{
        mNameLabel->setContentsMargins(8,0,0,0);
        mNameLabel->setAlignment(Qt::AlignLeft);
        pGLayout->addWidget(mIconLabel, 0, 0, 2,1, Qt::AlignTop);
        pGLayout->addWidget(mNameLabel, 0,1, 1,1);
        pGLayout->addWidget(mBubble, 1,1, 1,1);
        pGLayout->addItem(pSpacer, 2, 2, 1, 1);
        pGLayout->setColumnStretch(1, 3);
        pGLayout->setColumnStretch(2, 2);
    }
    this->setLayout(pGLayout);
}

void chatItemBase::setUserName(const QString &name)
{
    mNameLabel->setText(name);
}

void chatItemBase::setUserIcon(const QPixmap &icon)
{
    mIconLabel->setPixmap(icon);
}

void chatItemBase::setWidget(QWidget *w)
{
    QGridLayout *pGLayout = (qobject_cast<QGridLayout *>)(this->layout());
    pGLayout->replaceWidget(mBubble, w);
    delete mBubble;
    mBubble = w;
}
