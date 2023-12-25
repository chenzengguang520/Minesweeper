#include "MyPushButton.h"

MyPushButton::MyPushButton(QObject *parent)
	: QPushButton()
{}

MyPushButton::MyPushButton() {}
MyPushButton::MyPushButton(QString text)
{
	this->setText(text);
	QSize sizeHint = this->sizeHint();
	this->setFixedSize(sizeHint);
}
;

MyPushButton::~MyPushButton()
{}



