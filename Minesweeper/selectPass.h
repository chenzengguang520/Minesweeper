#pragma once

#include <QWidget>
#include "ui_selectPass.h"
#include "MyPushButton.h"
#include "pass.h"
#include "MyWidget.h"
#include "PassPlus.h"

class selectPass : public MyWidget
{
	Q_OBJECT

public:
	selectPass(QWidget *parent = nullptr);
	void recivePlus(int num);
	void createWidget();
	~selectPass();

private:
	Ui::selectPassClass ui;
	pass* myPass = nullptr;
	int plus = 0;

signals:
	void sentLevel(int num);
	
};
