#pragma once

#include <QWidget>
#include "ui_basePass.h"
#include "Block.h"
#include "QVector"

class basePass : public QWidget
{
	Q_OBJECT

public:
	basePass(QWidget *parent = nullptr);
	basePass();
	void calculateBombNum();
	~basePass();
	int getLevel();

public slots:
	void setBaseCase(int num);
private:
	int checkBomb(int x, int y, int m, int n);


private:
	Ui::basePassClass ui;
	int level;

public:
	int bombNum;
	int widthNum;
	int heightNum;
	QVector<QVector<Block*>>blocks;
};
