#pragma once

#include <QObject>
#include "MyTimer.h"
#include <Qdebug>

class TimeWorker  : public QObject
{
	Q_OBJECT

public:
	TimeWorker(QObject *parent = nullptr);
	~TimeWorker();

public slots:
	void work();
	void alarm();
	void timeOut();
public:

	MyTimer* myAlarmTimer = nullptr;
	int passTime = 0;
signals:
	void sendTime(int num);
	void sendSecond(int num);
};
