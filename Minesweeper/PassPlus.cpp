#include "PassPlus.h"

PassPlus::PassPlus(QWidget *parent)
	: pass(parent)
{
	ui.setupUi(this);

	plusTimePointer = QSharedPointer<QLabel>::create();
	alarmThread = QSharedPointer<QThread>::create();

	plusTimePointer->setParent(this);
	plusTimePointer->setText(QString::number(alarmNum));
	plusTimePointer->move(this->width() * 0.5 - plusTimePointer->width() * 0.5, 0);
	plusTimePointer->resize(100, 20);
	plusTimePointer->show();

	alarmtimer = QSharedPointer<TimeWorker>::create();
	alarmtimer->moveToThread(alarmThread.get());
	alarmThread->start();
	//alarmtimer->alarm();


	connect(alarmtimer.get(), &TimeWorker::sendSecond, this, &PassPlus::alarmClock);

	backBtn = new MyPushButton("返回");
	backBtn->setParent(this);
	backBtn->move(this->width() - backBtn->width() - 5, this->height() - backBtn->height() - 5);
	backBtn->show();
	connect(backBtn, &QPushButton::clicked, this, &PassPlus::backWidget);

}

void PassPlus::alarmClock(int num)
{
	plusTimePointer->setText(QString::number(--alarmNum));
	qDebug() << alarmNum;
	if (alarmNum <= 0)
	{
		timeOut();
	}

}

void PassPlus::timeOut()
{
	qDebug() << "timeout";
}

void PassPlus::connectFunctionPlus()
{
	int m = blocks.size();
	qDebug() << m;
	int n = blocks[0].size();
	qDebug() << m << " " << n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			connect(blocks[i][j], &Block::sentClicked, this, &PassPlus::recoveryTime);
		}
	}
}

void PassPlus::recoveryTime(bool flag)
{
	alarmNum = 30;
}

void PassPlus::alarmBegin()
{
	alarmtimer->alarm();
	alarmNum = 30;
}

PassPlus::~PassPlus()
{}

void PassPlus::backWidget() 
{
	alarmNum = 30;
	alarmClock(30);
	pass::backWidget();
	alarmtimer->timeOut();
}
