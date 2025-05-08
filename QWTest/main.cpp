#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include "global.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //测试qss文件的添加写入
    QFile qss(":/style/stylefirst.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug("this is yes");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else
    {
        qDebug("this is error");
    }

    QString fileName = "config.ini";
    //同级的文件
    QString app_path = QCoreApplication::applicationDirPath();
    //拼接字符串用法
    QString config_path = QDir::toNativeSeparators(app_path + QDir::separator() + fileName );
    //防止意外再转为本地类型
               //seperator()为分隔符，linux为\ windows 为 /
    QSettings settings(config_path, QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://" + gate_host + ":" + gate_port;
    MainWindow w;
    w.show();
    return a.exec();
}
