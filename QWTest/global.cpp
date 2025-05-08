#include "global.h"

QString gate_url_prefix="";
//制作为默认的空

std::function<void(QWidget*)> repolish =[](QWidget* w){

    //卸掉style样式
    w->style()->unpolish(w);
    w->style()->polish(w);
};

std::function<QString(QString)> xorString = [](QString input){
    QString result = input;
    int length = input.length();
    ushort xor_code = length % 255;
    for(int i = 0 ;i <length;i++){
        result[i] = QChar(static_cast<ushort>(input[i].unicode() ^ xor_code));
        //静态加密
    }
    return result;
};
