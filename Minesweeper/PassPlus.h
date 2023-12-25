#pragma once

#include <QWidget>
#include "ui_PassPlus.h"
#include "pass.h"

class PassPlus : public pass
{
	Q_OBJECT

public:
	PassPlus(QWidget *parent = nullptr);
	void alarmClock(int num);
	void timeOut();
	void connectFunctionPlus();
	void recoveryTime(bool flag);
	void alarmBegin();
	~PassPlus();

public:
	void backWidget();
public:
	QSharedPointer<QLabel> plusTimePointer;
	QSharedPointer<TimeWorker> alarmtimer;
	QSharedPointer<QThread> alarmThread;
	int alarmNum = 30;


private:
	Ui::PassPlusClass ui;
	MyPushButton* backBtn;

signals:
	void sentTimeOut(bool flag);
};
