#pragma once

#include <QWidget>
#include "ui_basePass.h"
#include "Block.h"
#include "QVector"
#include "MyWidget.h"
#include "MyTimer.h"
#include <QLabel>
#include <QThreadPool>
#include <QThread>
#include "TimeWorker.h"

class basePass : public MyWidget
{
	Q_OBJECT

public:
	basePass(QWidget *parent = nullptr);
	basePass();
	void calculateBombNum();
	~basePass();
	int getLevel();
	void init();
	void timeBegin();
	void showBombNum(int num);

public slots:
	void setBaseCase(int num);
private:
	int checkBomb(int x, int y, int m, int n);


private:
	Ui::basePassClass ui;
	int level;

public:
	QLabel* labelTime = nullptr;
	TimeWorker* timeWorker = nullptr;
	int bombNum;
	int widthNum;
	int heightNum;
	QSet<Block*>s;
	QVector<QVector<Block*>>blocks;
	MyTimer* myTimer = nullptr;
	QSharedPointer<QLabel> bombNumberLabel;
	QVector<int>randNums;
};
