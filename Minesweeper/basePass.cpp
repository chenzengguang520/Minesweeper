#include "basePass.h"

basePass::basePass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

basePass::basePass() {}
void basePass::calculateBombNum()
{
	int m = blocks.size();
	int n = blocks[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			blocks[i][j]->text = checkBomb(i, j, m, n);
		}
	}

}
;

basePass::~basePass()
{}

void basePass::setBaseCase(int num)
{
	level = num;
}

int basePass::getLevel()
{
	return level;
}

int basePass::checkBomb(int x, int y, int m, int n)
{
	int ans = 0;
	if (x - 1 >= 0 && y - 1 >= 0)
	{
		ans += blocks[x - 1][y - 1]->isBomb;
	}

	if (x - 1 >= 0)
	{
		ans += blocks[x - 1][y]->isBomb;
	}

	if (x - 1 >= 0 && y + 1 < n)
	{
		ans += blocks[x - 1][y + 1]->isBomb;
	}

	if (y - 1 >= 0)
	{
		ans += blocks[x][y - 1]->isBomb;
	}

	if (y + 1 < n)
	{
		ans += blocks[x][y + 1]->isBomb;
	}

	if (x + 1 < m && y - 1 >= 0)
	{
		ans += blocks[x + 1][y - 1]->isBomb;
	}

	if (x + 1 < m)
	{
		ans += blocks[x + 1][y]->isBomb;
	}

	if (x + 1 < m && y + 1 < n)
	{
		ans += blocks[x + 1][y + 1]->isBomb;
	}
	return ans;

}
