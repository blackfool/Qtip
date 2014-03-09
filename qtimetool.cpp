#include "qtimetool.h"
#include <Qtime>

QTimeTool::QTimeTool()
{
}

//计算当前时间 到 目标时间的秒数
int QTimeTool::countWaitSeconds(int targetHour)
{
    QTime nowTime = QTime::currentTime();
    QTime targetTime = QTime(targetHour+1,0,0);
    return nowTime.secsTo(targetTime);
}
