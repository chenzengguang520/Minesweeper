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
public:
	int level;
private:
	Ui::passClass ui;

	QVector<QVector<int>>next = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
};
