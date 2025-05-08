#ifndef CLICKBTN_H
#define CLICKBTN_H

#include <QPushButton>
class clickBtn:public QPushButton
{
    Q_OBJECT
public:
    clickBtn(QWidget * parent = nullptr);
    ~clickBtn();//有构造就写析构
    void SetState(QString nomal, QString hover, QString press);//状态设置
protected:
    virtual void enterEvent(QEnterEvent *event) override; // 鼠标进入
    virtual void leaveEvent(QEvent *event) override;// 鼠标离开
    virtual void mousePressEvent(QMouseEvent *event) override; // 鼠标按下
    virtual void mouseReleaseEvent(QMouseEvent *event) override; // 鼠标释放
private:
    QString _normal;
    QString _hover;
    QString _press;
};

#endif // CLICKBTN_H
