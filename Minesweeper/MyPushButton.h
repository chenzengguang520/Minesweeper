#pragma once

#include <QPushButton>

class MyPushButton  : public QPushButton
{
	Q_OBJECT

public:
	MyPushButton(QObject *parent);
	MyPushButton();
	MyPushButton(QString text);
	~MyPushButton();
};
