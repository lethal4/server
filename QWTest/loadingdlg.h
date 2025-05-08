#ifndef LOADINGDLG_H
#define LOADINGDLG_H

#include <QDialog>

namespace Ui {
class loadingDlg;
}

class loadingDlg : public QDialog
{
    Q_OBJECT

public:
    explicit loadingDlg(QWidget *parent = nullptr);
    ~loadingDlg();

private:
    Ui::loadingDlg *ui;
};

#endif // LOADINGDLG_H
