#pragma once

#include "ui_pass.h"
#include "basePass.h"
#include "QDebug"
#include <QRandomGenerator>

class pass : public basePass
{
	Q_OBJECT

public:
	pass(QWidget *parent = nullptr);
	~pass();
	void plantBomb();
public:
	int level;
private:
	Ui::passClass ui;
};
