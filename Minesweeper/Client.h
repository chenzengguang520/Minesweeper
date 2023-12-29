#pragma once

#include <QObject>
#include <QThread>
#include <QMessageBox>
#include "SenterAndRecord.h"

class Client  : public QObject
{
	Q_OBJECT

public:
	Client(QObject *parent = nullptr);
	~Client();
	void beginSentFile();
	void recvDataFromServer(QString str);
	void recv();
public:

	QString ip;
	unsigned short port;
	QVector<QVector<int>>vector;
	SenterAndRecord* worker = nullptr;
	void beginConnect(unsigned short port, QString ip);
	QString sentData;
	QString recvData;

signals:
	void startConnect(unsigned short port, QString);
	void sendFile(QString Data);
	void updata();

};
