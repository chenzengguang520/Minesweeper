#include "pass.h"

pass::pass(QWidget *parent)
	: basePass(parent)
{
	ui.setupUi(this);

	this->setFixedSize(24 * 35, 24 * 21);

	

}

void pass::turnOver(QPair<bool, QPair<int, int>>p)
{

	int m = blocks.size();
	int n = blocks[0].size();

	int y = p.second.first;
	int x = p.second.second;

	Block* block = blocks[x][y];

	QQueue<Block*> q;
	q.enqueue(block);

	QSet<Block*>s;

	while (!q.empty())
	{
		Block* cur = q.dequeue();
		cur->isShow = true;
		x = cur->posy;
		y = cur->posx;
		cur->changeText();
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
						nextblock->changeText();
					}
					else
					{
						q.enqueue(nextblock);
						s.insert(nextblock);
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
		for (int i = 0; i < 9 * 9; i++)
		{
			Block* block = new Block();
			blocks[i / 9].resize(9);
			blocks[i / 9][i % 9] = block;
			block->posx = i % 9;
			block->posy = i / 9;
		}
		while (bombNum)
		{
			for (int i = 0; i < 9 && bombNum > 0; i++)
			{
				for (int j = 0; j < 9 && bombNum > 0; j++)
				{
					if (!blocks[i][j]->isBomb)
					{
						if (QRandomGenerator::global()->bounded(20) == 1)
						{
							blocks[i][j]->isBomb = 1;
							bombNum--;
						}
					}
				}
			}
		}
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
		blocks.resize(16);
		for (int i = 0; i < 16 * 16; i++)
		{
			Block* block = new Block();
			blocks[i / 16].resize(16);
			blocks[i / 16][i % 16] = block;
			block->posx = i % 16;
			block->posy = i / 16;
		}
		while (bombNum)
		{
			for (int i = 0; i < 16 && bombNum > 0; i++)
			{
				for (int j = 0; j < 16 && bombNum > 0; j++)
				{
					if (!blocks[i][j]->isBomb)
					{
						if (QRandomGenerator::global()->bounded(20) == 1)
						{
							blocks[i][j]->isBomb = 1;
							bombNum--;
						}
					}
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
		blocks.resize(16);
		for (int i = 0; i < 16 * 30; i++)
		{
			Block* block = new Block();
			blocks[i / 30].resize(30);
			blocks[i / 30][i % 30] = block;
			block->posx = i % 30;
			block->posy = i / 30;
		}

		while (bombNum)
		{
			for (int i = 0; i < 16 && bombNum > 0; i++)
			{
				for (int j = 0; j < 30 && bombNum > 0; j++)
				{
					if (!blocks[i][j]->isBomb)
					{
						if (QRandomGenerator::global()->bounded(20) == 1)
						{
							blocks[i][j]->isBomb = 1;
							bombNum--;
						}
					}
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
		}
	}
}
