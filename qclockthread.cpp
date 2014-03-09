#include "qclockthread.h"
#include "qtipdlg.h"

#include <Qtime>

QClockThread::QClockThread(QObject *parent) :
    QThread(parent)
{
    //tipDlg = new QTipDlg;
}

void QClockThread::run()
{
    QTime nowTime = QTime::currentTime();
    int nowHour = nowTime.hour();
    QTime targetTime = QTime(nowHour,59,59);//到下一个 整点时钟

    int seconds = nowTime.secsTo(targetTime)+1;
    //sleep(seconds);

    QTipDlg* w = new QTipDlg;

    w->show();
    //tipDlg->show();
}
