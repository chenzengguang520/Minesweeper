#pragma once

#include <QPushButton>
#include <QMouseEvent>

class MyPushButton  : public QPushButton
{
	Q_OBJECT

public:

	MyPushButton(QObject *parent);
	MyPushButton();
	MyPushButton(QString text);
	~MyPushButton();

protected:
protected:
};
