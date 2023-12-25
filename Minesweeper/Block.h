#pragma once

#include <QObject>
#include "MyPushButton.h"

class Block  : public MyPushButton
{
	Q_OBJECT

public:
	Block(QObject *parent);
	Block();
	bool changeText();
	void mousePressEvent(QMouseEvent* e);
	void explode();
	void turn();
	~Block();
public:
	int isBomb = 0;
	int text;
	int posx;
	int posy;
	bool canPress = true;
	bool isShow = false;

signals:
	void sentPress(QPair<bool,QPair<int,int>>);
	void sendBombNum(int num);
	void sentExplode(bool flag);
	void sentClicked(bool flag);
};
