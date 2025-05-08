#include "customedit.h"

customEdit::customEdit(QWidget *parent):QLineEdit (parent),_max_len(0)
{
    connect(this, &QLineEdit::textChanged, this, &customEdit::limitTextLength);
}

void customEdit::SetMaxLength(int maxLen)
{
    _max_len = maxLen;
}
