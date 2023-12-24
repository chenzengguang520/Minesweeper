#include "selectPass.h"

selectPass::selectPass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->resize(512 + 2 * 128, 512);

	MyPushButton* btn1 = new MyPushButton("简单");
	MyPushButton* btn2 = new MyPushButton("中等");
	MyPushButton* btn3 = new MyPushButton("困难");

	btn1->setParent(this);
	btn2->setParent(this);
	btn3->setParent(this);
	
	btn1->move(this->width() * 0.5 - btn1->width() * 0.5, this->height() * 0.5);
	btn2->move(this->width() * 0.5 - btn2->width() * 0.5, this->height() * 0.5 + btn2->height() + 5);
	btn3->move(this->width() * 0.5 - btn3->width() * 0.5, this->height() * 0.5 + 2 * btn3->height() + 5);

	myPass = new pass();

	connect(this, &selectPass::sentLevel, myPass, &pass::setBaseCase);

	connect(btn1, &QPushButton::clicked, this, [=]() 
	{
		emit sentLevel(1);
		this->hide();
		myPass->plantBomb();
		myPass->show();
	});

	connect(btn2, &QPushButton::clicked, this, [=]()
	{
		emit sentLevel(2);
		this->hide();
		myPass->plantBomb();
		myPass->show();
	});

	connect(btn3, &QPushButton::clicked, this, [=]()
	{
		emit sentLevel(3);
		this->hide();
		myPass->plantBomb();
		myPass->show();
	});



}

selectPass::~selectPass()
{}
