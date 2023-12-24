#pragma once

#include <QWidget>
#include "ui_selectPass.h"
#include "MyPushButton.h"
#include "pass.h"

class selectPass : public QWidget
{
	Q_OBJECT

public:
	selectPass(QWidget *parent = nullptr);
	~selectPass();

private:
	Ui::selectPassClass ui;
	pass* myPass = nullptr;

signals:
	void sentLevel(int num);
};
