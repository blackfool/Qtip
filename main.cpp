//#include "qtipdlg.h"
#include "qwelcomedlg.h"
#include <QApplication>
#include <QSettings>
#include <QDesktopWidget>
#include <QRect>
#include <QtDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTipDlg w;
//    w.show();
    QDesktopWidget *dwsktopwidget = QApplication::desktop();
    QRect deskrect = dwsktopwidget->availableGeometry();
    QRect screenrect = dwsktopwidget->screenGeometry();

    int scrcount = dwsktopwidget->screenCount();
    qDebug()<<"screenrect.w:"<<screenrect.width();
    qDebug()<<"screenrect.h:"<<screenrect.height();
    qDebug()<<"deskrect.w:"<<deskrect.width();
    qDebug()<<"deskrect.h:"<<deskrect.height();


    qDebug()<<"scrcount:"<<scrcount;

    QSettings *reg=new QSettings("HKEY_LOCAL_MACHINE//SOFTWARE//Microsoft"
                                 "//Windows//CurrentVersion//Run//QtApp",QSettings::NativeFormat);
    reg->setValue("QTIPS",QApplication::applicationFilePath());

    //qDebug("----",qPrintable(QApplication::applicationFilePath()));
    qDebug()<<"---"<<QApplication::applicationFilePath();

    QWelcomeDlg welcomeDlg;
    welcomeDlg.show();
    return a.exec();
}



