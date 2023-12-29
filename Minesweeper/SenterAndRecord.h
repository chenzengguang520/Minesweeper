#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QFile>
#include <QFileInfo>

class SenterAndRecord  : public QObject
{
	Q_OBJECT

public:
	SenterAndRecord(QObject *parent = nullptr);
	~SenterAndRecord();

	void sentFile(QString path);
	void recvFile();
	void sentData(QString data);
	QString recvData();
	void connectServer(unsigned short port, QString str);
private:
	QTcpSocket* m_tcp = nullptr;
signals:
	void gameOver();
	void connectOK();
	void recvDataFromServer(QString str);
};
