#pragma once

#include <QObject>
#include "MyPushButton.h"

class Block  : public MyPushButton
{
	Q_OBJECT

public:
	Block(QObject *parent);
	Block();
	void changeText();
	~Block();
public:
	int isBomb = 0;
	int text;
};
