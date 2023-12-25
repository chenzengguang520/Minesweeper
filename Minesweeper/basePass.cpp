#include "basePass.h"

basePass::basePass(QWidget *parent)
	: MyWidget()
{
	ui.setupUi(this);

	bombNumberLabel = QSharedPointer<QLabel>::create();

	bombNumberLabel->setParent(this);

}

basePass::basePass() : MyWidget() {};
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

void basePass::init() 
{
	delete timeWorker;
	delete labelTime;
	int m = blocks.size();
	int n = blocks[0].size();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			delete blocks[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		blocks[i].clear();
	}
	blocks.clear();
}

void basePass::timeBegin()
{
	labelTime = new QLabel();
	labelTime->setParent(this);
	labelTime->show();
	labelTime->move(0, 0);
	labelTime->resize(100, 20);
	//labelTime->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

	timeWorker = new TimeWorker();
	connect(timeWorker, &TimeWorker::sendTime, this, [=](int passTime) {
		//qDebug() << QString::number(30);
		labelTime->setText(QString::number(passTime));
		//labelTime->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

	});

	QThread* timeThread = new QThread();
	timeWorker->moveToThread(timeThread);
	timeThread->start();

	timeWorker->work();
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

void basePass::showBombNum(int num)
{
	bombNum += num;
	bombNumberLabel->setText(QString::number(bombNum));
	bombNumberLabel->resize(100, 20);
	bombNumberLabel->move(this->width() - bombNumberLabel->width(), 0);
	bombNumberLabel->show();
	return;
}