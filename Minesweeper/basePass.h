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
#include "Client.h"
#include "MyPushButton.h"

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
	void startConnect();
	QString transformToString();
	void transfromStringToVector();

public slots:
	void setBaseCase(int num);

private:
	int checkBomb(int x, int y, int m, int n);
	QVector<int> splitString(QString str);

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
	QVector<QVector<int>>bombState;//0代表没翻面，1代表翻面
	Client* client = nullptr;

signals:
	void sendbombState(QVector<QVector<int>>);
};
