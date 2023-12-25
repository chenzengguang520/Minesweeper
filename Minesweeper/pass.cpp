#include "pass.h"

pass::pass(QWidget *parent)
	: basePass(parent)
{
	ui.setupUi(this);

	this->setFixedSize(24 * 35, 24 * 21);

	backBtn = new MyPushButton("返回");
	backBtn->setParent(this);
	backBtn->move(this->width() - backBtn->width() - 5, this->height() - backBtn->height() - 5);
	backBtn->show();

	connect(backBtn, &QPushButton::clicked, this, &pass::backWidget);

}

void pass::turnOver(QPair<bool, QPair<int, int>>p)
{
	int m = blocks.size();
	int n = blocks[0].size();

	int y = p.second.first;
	int x = p.second.second;

	Block* block = blocks[x][y];

	if (block->text != 0)
	{
		block->isShow = true;
		bool ret = block->changeText();
		s.insert(block);
		block->canPress = false;
		if (s.size() == surplus)
		{
			youVectory();
			return;
		}
		return;
	}

	QQueue<Block*> q;
	q.enqueue(block);

	while (!q.empty())
	{
		Block* cur = q.dequeue();
		cur->isShow = true;
		x = cur->posy;
		y = cur->posx;
		bool ret = cur->changeText();
		s.insert(cur);
		cur->canPress = false;
		if (s.size() == surplus)
		{
			youVectory();
			return;
		}
		for (int i = 0; i < 8;i++)
		{
			int nextx = x + next[i][0];
			int nexty = y + next[i][1];
			if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n)
			{
				Block* nextblock = blocks[nextx][nexty];
				if (nextblock->canPress && s.find(nextblock) == s.end() && !nextblock->isBomb)
				{
					if (nextblock->text != 0)
					{
						nextblock->isShow = true;
						bool ret = nextblock->changeText();
						s.insert(nextblock);
						nextblock->canPress = false;
					}
					else
					{
						q.enqueue(nextblock);
					}
					if (s.size() == surplus)
					{
						youVectory();
						return;
					}
				}
			}
		}
	}
}


pass::~pass()
{}

void pass::plantBomb()
{
	//level = 1 10,level = 2 40,level = 3 99

	level = getLevel();
	switch (level)
	{
	case 1:
		bombNum = 10;
		blocks.resize(9);
		surplus = 9 * 9 - 10;
		for (int i = 0; i < 9 * 9; i++)
		{
			Block* block = new Block();
			blocks[i / 9].resize(9);
			blocks[i / 9][i % 9] = block;
			block->posx = i % 9;
			block->posy = i / 9;
		}
		for (int i = 0; i < bombNum; i++)
		{
			int randNum = QRandomGenerator::global()->bounded(10000);
			int modNum = randNum % (9 * 9);
			bool flag = false;
			while (!flag)
			{
				if (!blocks[modNum / 9][modNum % 9]->isBomb)
				{
					blocks[modNum / 9][modNum % 9]->isBomb = 1;
					flag = true;
				}
				else
				{
					modNum = modNum + 1 >= 9 * 9 ? 0 : modNum + 1;
				}
			}

		}

		//bombNum = 10;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				Block* block = blocks[i][j];
				//棋盘左上角
				int initx = this->width() * 0.5 - 5 * block->width();
				int inity = this->height() * 0.5 - 5 * block->height();
				block->setParent(this);
				block->move(initx + j * block->width(), inity + block->height() * i);
				calculateBombNum();
				block->show();
			}
		}
		break;
	case 2:
		bombNum = 40;
		surplus = 16 * 16 - 40;
		blocks.resize(16);
		for (int i = 0; i < 16 * 16; i++)
		{
			Block* block = new Block();
			blocks[i / 16].resize(16);
			blocks[i / 16][i % 16] = block;
			block->posx = i % 16;
			block->posy = i / 16;
		}
		for (int i = 0; i < bombNum; i++)
		{
			int randNum = QRandomGenerator::global()->bounded(10000);
			int modNum = randNum % (16 * 16);
			bool flag = false;
			while (!flag)
			{
				if (!blocks[modNum / 16][modNum % 16]->isBomb)
				{
					blocks[modNum / 16][modNum % 16]->isBomb = 1;
					flag = true;
				}
				else
				{
					modNum = modNum + 1 >= 16 * 16 ? 0 : modNum + 1;
				}
			}

		}
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				Block* block = blocks[i][j];
				//棋盘左上角
				int initx = this->width() * 0.5 - 8 * block->width();
				int inity = this->height() * 0.5 - 8 * block->height();
				block->setParent(this);
				block->move(initx + j * block->width(), inity + block->height() * i);
				calculateBombNum();
				block->show();
			}
		}
		break;
	case 3:
		bombNum = 99;
		surplus = 16 * 30 - 99;
		blocks.resize(16);
		for (int i = 0; i < 16 * 30; i++)
		{
			Block* block = new Block();
			blocks[i / 30].resize(30);
			blocks[i / 30][i % 30] = block;
			block->posx = i % 30;
			block->posy = i / 30;
		}

		for (int i = 0; i < bombNum; i++)
		{
			int randNum = QRandomGenerator::global()->bounded(10000);
			int modNum = randNum % (16 * 30);
			bool flag = false;
			while (!flag)
			{
				if (!blocks[modNum / 30][modNum % 30]->isBomb)
				{
					blocks[modNum / 30][modNum % 30]->isBomb = 1;
					flag = true;
				}
				else
				{
					modNum = modNum + 1 >= 16 * 30 ? 0 : modNum + 1;
				}
			}

		}

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				Block* block = blocks[i][j];
				//棋盘左上角
				int initx = this->width() * 0.5 - 15 * block->width();
				int inity = this->height() * 0.5 - 8 * block->height();
				block->setParent(this);
				block->move(initx + j * block->width(), inity + block->height() * i);
				calculateBombNum();
				block->show();
			}
		}
		break;
	default:
		break;
	}

	connectFunction();
	timeBegin();
	showBombNum(0);
}

void pass::connectFunction()
{
	int m = blocks.size();
	int n = blocks[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			connect(blocks[i][j], &Block::sentPress, this, &pass::turnOver);
			connect(blocks[i][j], &Block::sendBombNum, this, &pass::showBombNum);
			connect(blocks[i][j], &Block::sentExplode, this, &pass::gameOver);
		}
	}
}

void pass::youVectory()
{
	qDebug() << "success";
}

void pass::backWidget()
{

	this->hide();
	init();
	surplus = 0;
	s.clear();
	emit sentShow(true);

}

void pass::gameOver()
{
	qDebug() << "gameover";

	int m = blocks.size();
	int n = blocks[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!blocks[i][j]->isShow)
			{
				blocks[i][j]->changeText();
			}
		}
	}

}
