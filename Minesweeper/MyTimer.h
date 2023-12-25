#pragma once

#include <QObject>
#include <QTimer>

class MyTimer  : public QObject,public QTimer
{
	Q_OBJECT

public:
	MyTimer(QObject *parent);
	MyTimer();
	~MyTimer();
};
