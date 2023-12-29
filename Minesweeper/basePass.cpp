#include "basePass.h"

basePass::basePass(QWidget *parent)
	: MyWidget()
{
	ui.setupUi(this);

	

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
		bombState[i].clear();
	}
	blocks.clear();
	bombState.clear();
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

QVector<int> basePass::splitString(QString str)
{
	QVector<int>v;
	int sz = str.size();
	int l = 0;
	while (l < sz)
	{
		if (str[l] != '\u0000')
		{
			qDebug() << "str[l] = " << str[l].unicode();
			v.push_back(str[l].unicode() - '0');
		}
		else break;
		l++;
	}
	return v;
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

void basePass::startConnect()
{
	unsigned short port = 10000;
	QString ip = "43.143.238.28";
	client->sentData = transformToString();
	client->beginConnect(port,ip);
}

QString basePass::transformToString()
{
	QString str = QString::number(level);
	int m = bombState.size();
	int n = bombState[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			str += QString::number(bombState[i][j]);
		}
	}
	qDebug() << "str = " << str;
	return str;
}

void basePass::transfromStringToVector()
{
	QString str = client->recvData;
	qDebug() << "str = " << str;
	QVector<int>v = splitString(str);
	qDebug() << "str[0] = " << str[0];
	int sz = v.size();
	switch (v[0])
	{
	case 1:
		qDebug() << "case1";
		// 9 * 9
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				bombState[i][j] = v[i * 9 + j + 1];
			}
		}
		break;
	case 2:
		qDebug() << "case2";
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				bombState[i][j] = v[i * 16 + j + 1];
			}
		}
		break;
	case 3:
		qDebug() << "case3";
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				bombState[i][j] = v[i * 30 + j + 1];
			}
		}
		break;
	default:
		break;
	}
	qDebug() << transformToString();
}
