#ifndef QTIPDLG_H
#define QTIPDLG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class QTipDlg;
}

class QTipDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit QTipDlg(QWidget *parent = 0);
    ~QTipDlg();
    
private slots:
    void on_pushbutton_ok_clicked();
    void showTip();

private:
    Ui::QTipDlg *ui;
};

#endif // QTIPDLG_H
