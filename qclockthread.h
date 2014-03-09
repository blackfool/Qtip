#ifndef QCLOCKTHREAD_H
#define QCLOCKTHREAD_H
#include <qtipdlg.h>
#include <QThread>

class QClockThread : public QThread
{
    Q_OBJECT
public:
    explicit QClockThread(QObject *parent = 0);

    void run();

private:

    QTipDlg* tipDlg;
    
};

#endif // QCLOCKTHREAD_H
