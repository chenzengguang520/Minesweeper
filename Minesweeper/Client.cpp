#include "Client.h"

Client::Client(QObject *parent)
	: QObject(parent)
{
	QThread* t = new QThread();
	
	worker = new SenterAndRecord();
	worker->moveToThread(t);

	t->start();

	connect(worker, &SenterAndRecord::recvDataFromServer, this,&Client::recvDataFromServer);

	connect(this, &Client::startConnect, worker, &SenterAndRecord::connectServer);

	connect(this, &Client::sendFile, worker, &SenterAndRecord::sentData);
	
	connect(worker, &SenterAndRecord::connectOK, this, [=]() {

		//QMessageBox::information(this, "连接服务器", "已经成功连接了服务器");

	});

	connect(worker, &SenterAndRecord::gameOver, this, [=]() {

		t->quit();
		t->wait();
		worker->deleteLater();
		t->deleteLater();

	});

	//connect(worker, &SenterAndRecord::curPercent, ui.progressBar, &QProgressBar::setValue);

}

Client::~Client()
{}

void Client::beginSentFile()
{
	emit sendFile(sentData);
}

void Client::recvDataFromServer(QString str)
{
	recvData = str;
	qDebug() << "Client:Str = " << str;
	emit updata();
}

void Client::recv()
{

}

void Client::beginConnect(unsigned short port, QString ip)
{
	emit startConnect(port, ip);
}