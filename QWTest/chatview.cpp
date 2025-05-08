#include "chatview.h"
#include <QScrollBar>
#include <QEvent>
#include <QStyleOption>
#include <QPainter>
chatView::chatView(QWidget *parent) :QWidget(parent), isAppended(false)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();//垂直布局
    this->setLayout(pMainLayout);
    pMainLayout->setContentsMargins(0, 0, 0, 0); // 替代 setMargin设置间距

    m_pScrollArea = new QScrollArea();
    m_pScrollArea->setObjectName("chat_area");
    pMainLayout->addWidget(m_pScrollArea);


    QWidget *w = new QWidget(this);//指定父窗口
    w->setObjectName("chat_bg");
    w->setAutoFillBackground(true);//充满背景

    QVBoxLayout *pVLayout_1 = new QVBoxLayout();
    pVLayout_1->addWidget(new QWidget(), 100000);//伸缩因子
    w->setLayout(pVLayout_1);
    m_pScrollArea->setWidget(w);

    m_pScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//关闭垂直滚动条
    QScrollBar *pVScrollBar = m_pScrollArea->verticalScrollBar();
    connect(pVScrollBar, &QScrollBar::rangeChanged,this, &chatView::onVScrollBarMoved);


    QHBoxLayout *pHLayout_2 = new QHBoxLayout();//把垂直ScrollBar放到上边
    pHLayout_2->addWidget(pVScrollBar, 0, Qt::AlignRight);
    pHLayout_2->setContentsMargins(0, 0, 0, 0);
    m_pScrollArea->setLayout(pHLayout_2);
    pVScrollBar->setHidden(true);

    m_pScrollArea->setWidgetResizable(true);
    m_pScrollArea->installEventFilter(this);
    initStyleSheet();
}

void chatView::appendChatItem(QWidget *item)
{
    QVBoxLayout *vl = qobject_cast<QVBoxLayout *>(m_pScrollArea->widget()->layout());
    vl->insertWidget(vl->count()-1, item);
    isAppended = true;
}

void chatView::prependChatItem(QWidget *item)
{

}

void chatView::insertChatItem(QWidget *before, QWidget *item)
{

}

void chatView::removeAllItem()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(m_pScrollArea->widget()->layout());

    int count = layout->count();

    for (int i = 0; i < count - 1; ++i) {
        QLayoutItem *item = layout->takeAt(0); // 始终从第一个控件开始删除
        if (item) {
            if (QWidget *widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
    }
}

bool chatView::eventFilter(QObject *o, QEvent *e)
{
    if(e->type() == QEvent::Enter && o == m_pScrollArea)//进入
    {
        m_pScrollArea->verticalScrollBar()->setHidden(m_pScrollArea->verticalScrollBar()->maximum() == 0);
    }
    else if(e->type() == QEvent::Leave && o == m_pScrollArea)//退出
    {
        m_pScrollArea->verticalScrollBar()->setHidden(true);
    }
    return QWidget::eventFilter(o, e);//处理其他基类的情况
}

void chatView::paintEvent(QPaintEvent *event)//实现复杂的样式结构
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void chatView::onVScrollBarMoved(int min, int max)
{
    if(isAppended)
    {
        QScrollBar *pVScrollBar = m_pScrollArea->verticalScrollBar();
        pVScrollBar->setSliderPosition(pVScrollBar->maximum());
        QTimer::singleShot(555, [this](){
            isAppended = false;//防止重复响应造成卡顿
        });
    }
}

void chatView::initStyleSheet()
{

}
