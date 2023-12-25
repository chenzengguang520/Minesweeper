#pragma once

#include <QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget();
	~MyWidget();

private:
	Ui::MyWidgetClass ui;
};
