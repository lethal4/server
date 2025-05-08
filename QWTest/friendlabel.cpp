#include "friendLabel.h"
#include "ui_friendLabel.h"
#include <QDebug>

friendLabel::friendLabel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::friendLabel)
{
    ui->setupUi(this);
    ui->close_lb->SetState("normal","hover","pressed",
                           "selected_normal","selected_hover","selected_pressed");
    connect(ui->close_lb, &clickedLabel::clicked, this, &friendLabel::slot_close);
}

friendLabel::~friendLabel()
{
    delete ui;
}

void friendLabel::SetText(QString text)
{
    _text = text;
    ui->tip_lb->setText(_text);
    ui->tip_lb->adjustSize();

    QFontMetrics fontMetrics(ui->tip_lb->font()); // 获取QLabel控件的字体信息
    //auto textWidth = fontMetrics.width(ui->tip_lb->text()); // 获取文本的宽度
    auto textWidth = fontMetrics.horizontalAdvance(ui->tip_lb->text());
    auto textHeight = fontMetrics.height(); // 获取文本的高度

    qDebug()<< " ui->tip_lb.width() is " << ui->tip_lb->width();
    qDebug()<< " ui->close_lb->width() is " << ui->close_lb->width();
    qDebug()<< " textWidth is " << textWidth;
    this->setFixedWidth(ui->tip_lb->width()+ui->close_lb->width()+5);
    this->setFixedHeight(textHeight+2);
    qDebug()<< "  this->setFixedHeight " << this->height();
    _width = this->width();
    _height = this->height();
}

int friendLabel::Width()
{
    return _width;
}

int friendLabel::Height()
{
    return _height;
}

QString friendLabel::Text()
{
    return _text;
}

void friendLabel::slot_close()
{
    emit sig_close(_text);
}
