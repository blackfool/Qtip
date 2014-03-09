#ifndef QWELCOMEDLG_H
#define QWELCOMEDLG_H

#include <QDialog>

namespace Ui {
class QWelcomeDlg;
}

class QWelcomeDlg : public QDialog
{
    Q_OBJECT

public:

    explicit QWelcomeDlg(QWidget *parent = 0);
    ~QWelcomeDlg();

private slots:
    void on_pushbutton_ok_clicked();
    void showTip();

private:
    Ui::QWelcomeDlg *ui;
};

#endif // QWELCOMEDLG_H
