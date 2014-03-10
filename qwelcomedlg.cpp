#include "qwelcomedlg.h"
#include "qclockthread.h"
#include "ui_qwelcomedlg.h"
#include "qtipdlg.h"
#include <QTimer>
#include <QDebug>
#include <QDesktopWidget>
#include <QRect>

QWelcomeDlg::QWelcomeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWelcomeDlg)
{
    ui->setupUi(this);
    QDesktopWidget *dwsktopwidget = QApplication::desktop();
    QRect screenrect = dwsktopwidget->screenGeometry();

    this->setWindowFlags(Qt::FramelessWindowHint);
    QString imgStyle = "border-image: url(:/pic/pic/background";
    QString imgStr = ".jpg);";

    //搞一个随机数字  1-10对应图片的文件名 数字
    int picNo = qrand()%10+1;
    this->ui->graphicsView->setStyleSheet(imgStyle+QString::number(picNo)+imgStr);
    this->setGeometry(screenrect.width()-480+160,screenrect.height()-240-60,300,240);
}

QWelcomeDlg::~QWelcomeDlg()
{
    delete ui;
}

void QWelcomeDlg::on_pushbutton_ok_clicked()
{
    this->hide();

    QTime nowTime = QTime::currentTime();
    int nowHour = nowTime.hour();
    QTime targetTime = QTime(nowHour,59,59);//到下一个 整点时钟
    int seconds = nowTime.secsTo(targetTime)+1;
    qDebug()<<seconds;
    /*
        计算从这次点击确定之后，到下一个整点，还有多少秒
     */
    QTimer::singleShot(seconds*10, this, SLOT(showTip()));

}

void QWelcomeDlg::showTip()
{
    QTipDlg* w = new QTipDlg;
    w->show();
}
