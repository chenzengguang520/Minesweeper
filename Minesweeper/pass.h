#pragma once

#include "ui_pass.h"
#include "basePass.h"
#include "QDebug"
#include <QRandomGenerator>
#include <QQueue>
#include <QSet>

class pass : public basePass
{
	Q_OBJECT

public:
	pass(QWidget *parent = nullptr);
	void turnOver(QPair<bool,QPair<int,int>>);
	~pass();
	void plantBomb();
	void connectFunction();
	void youVectory();
	void backWidget();
	void gameOver();
public:
	int level;
	int surplus;
private:
	Ui::passClass ui;
	MyPushButton* backBtn;
	QVector<QVector<int>>next = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };


signals:
	void sentShow(bool flag);
};
