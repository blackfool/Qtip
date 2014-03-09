#include "qtipdlg.h"
#include "ui_qtipdlg.h"
#include "qtimetool.h"
#include <QTimer>
#include <QDebug>
#include <QDesktopWidget>
#include <QRect>

QTipDlg::QTipDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTipDlg)
{
    ui->setupUi(this);
    QDesktopWidget *dwsktopwidget = QApplication::desktop();
    QRect screenrect = dwsktopwidget->screenGeometry();
//    qCritical("screenrect.w==%s\n",qPrintable(QString::number(screenrect.width())));
//    qCritical("screenrect.h==%s\n",qPrintable(QString::number(screenrect.height())));

    this->setGeometry(screenrect.width()-500+160,screenrect.height()-240-60,300,240);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QTime nowTime = QTime::currentTime();
    int nowHour = nowTime.hour();
    QTime targetTime = QTime(nowHour,59,59);//到下一个 整点时钟

    int seconds = nowTime.secsTo(targetTime)+1;

    ui->labelTime->setText("现在是北京时间"+nowTime.toString("hh点mm分"));
    QString secs = QString::number(seconds,10);

    ui->labelTip->setText("请休息一下吧  ");
}

QTipDlg::~QTipDlg()
{
    delete ui;
}

void QTipDlg::on_pushbutton_ok_clicked()
{
    this->hide();

    QTime nowTime = QTime::currentTime();
    int nowHour = nowTime.hour();
    QTime targetTime = QTime(nowHour,59,59);//到下一个 整点时钟
    int seconds = nowTime.secsTo(targetTime)+1;
    qDebug()<<seconds;

    QTimer::singleShot(seconds*1000, this, SLOT(showTip()));

}

void QTipDlg::showTip()
{
    QTipDlg* w = new QTipDlg;
}
