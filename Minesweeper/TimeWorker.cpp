#include "TimeWorker.h"

TimeWorker::TimeWorker(QObject *parent)
	: QObject(parent)
{}

TimeWorker::~TimeWorker()
{}

void TimeWorker::alarm()
{
	myAlarmTimer = new MyTimer();
	myAlarmTimer->start(1000);
	passTime = 0;
	connect(myAlarmTimer, &QTimer::timeout, this, [=]()
	{
		//qDebug() << "working";
		emit sendSecond(1);
	});
}

void TimeWorker::timeOut()
{
	myAlarmTimer->stop();
}

void TimeWorker::work()
{
	MyTimer* myTimer = new MyTimer();
	myTimer->start(1000);
	passTime = 0;
	connect(myTimer, &QTimer::timeout, this, [=]() 
	{
		//qDebug() << "working";
		emit sendTime(++passTime);
	});
}