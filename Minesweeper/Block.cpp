#include "Block.h"

Block::Block(QObject *parent)
	: MyPushButton(parent)
{}

Block::Block()
{
	this->setFixedSize(24, 24);
	// 使用样式表设置背景颜色为纯黑色
    this->setStyleSheet("background-color: rgb(45, 62, 74); color: white; border: 0.5px solid black;");
}
void Block::changeText()
{
	if (canPress)
	{
		if (isBomb)
		{
			this->setText("*");
		}
		else
		{
			this->setText(QString::number(text));
		}
		this->setStyleSheet("background-color: white; color: black; border: 0.5px solid black;");
	}

}

void Block::mousePressEvent(QMouseEvent* e)
{
	if (isShow)
		return;
	if (e->button() == Qt::LeftButton && this->canPress)
	{
		switch (this->isBomb)
		{
		case 1:
			explode(); break;
		case 0:
		{
			if(this->text == 0)
				sentPress({ true,{posx,posy} });
			if (this->text != 0)
			{
				isShow = true;
				changeText();
			}
			break;
		}
		default:
			break;
		}	
	}
	if (e->button() == Qt::RightButton)
	{
		turn();
	}
}

void Block::explode()
{
	
}

void Block::turn()
{
	if (canPress)
	{
		this->canPress = false;
		this->setStyleSheet("background-color: rgb(149, 220, 237); color: white; border: 0.5px solid black;");
	}
	else
	{
		this->canPress = true;
		this->setStyleSheet("background-color: rgb(45, 62, 74); color: white; border: 0.5px solid black;");
	}
}

Block::~Block() {};
