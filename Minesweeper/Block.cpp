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
	this->setText(QString::number(isBomb) + QString::number(text));

}
;

Block::~Block() {};
