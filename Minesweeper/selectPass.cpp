#include "selectPass.h"

selectPass::selectPass(QWidget *parent)
	: MyWidget()
{
	ui.setupUi(this);


	this->resize(512 + 2 * 128, 512);


	



}

void selectPass::recivePlus(int num)
{
	plus = num;
}

void selectPass::createWidget()
{

	MyPushButton* btn1 = new MyPushButton("简单");
	MyPushButton* btn2 = new MyPushButton("中等");
	MyPushButton* btn3 = new MyPushButton("困难");

	btn1->setParent(this);
	btn2->setParent(this);
	btn3->setParent(this);

	btn1->move(this->width() * 0.5 - btn1->width() * 0.5, this->height() * 0.5);
	btn2->move(this->width() * 0.5 - btn2->width() * 0.5, this->height() * 0.5 + btn2->height() + 5);
	btn3->move(this->width() * 0.5 - btn3->width() * 0.5, this->height() * 0.5 + 2 * btn3->height() + 5);

	qDebug() << plus;
	if (!plus)
		myPass = new pass();
	else
	{
		myPass = new PassPlus();
	}

	connect(myPass, &pass::sentShow, this, [=]() {

		this->show();

	});

	connect(this, &selectPass::sentLevel, myPass, &pass::setBaseCase);

	connect(btn1, &QPushButton::clicked, this, [=]()
	{
		emit sentLevel(1);
		this->hide();
		myPass->plantBomb();
		myPass->show();
		if (plus)
		{
			((PassPlus*)myPass)->connectFunctionPlus();
			((PassPlus*)myPass)->alarmBegin();
		}
	});

	connect(btn2, &QPushButton::clicked, this, [=]()
	{
		emit sentLevel(2);
		this->hide();
		myPass->plantBomb();
		myPass->show();
		if (plus)
		{
			((PassPlus*)myPass)->connectFunctionPlus();
			((PassPlus*)myPass)->alarmBegin();
		}
	});

	connect(btn3, &QPushButton::clicked, this, [=]()
	{
		emit sentLevel(3);
		this->hide();
		myPass->plantBomb();
		myPass->show();
		if (plus)
		{
			((PassPlus*)myPass)->connectFunctionPlus();
			((PassPlus*)myPass)->alarmBegin();
		}
	});

}

selectPass::~selectPass()
{}
