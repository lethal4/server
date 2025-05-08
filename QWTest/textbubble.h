#ifndef TEXTBUBBLE_H
#define TEXTBUBBLE_H
#include <QTextEdit>
#include "bubbleframe.h"
#include <QHBoxLayout>

class textBubble : public bubbleFrame
{
    Q_OBJECT
public:
    textBubble(ChatRole role, const QString &text, QWidget *parent = nullptr);
protected:
    bool eventFilter(QObject *o, QEvent *e);
private:
    void adjustTextHeight();
    void setPlainText(const QString &text);
    void initStyleSheet();
    QTextEdit *mTextEdit;
};

#endif // TEXTBUBBLE_H
