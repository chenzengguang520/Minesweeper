#include "SenterAndRecord.h"

SenterAndRecord::SenterAndRecord(QObject *parent)
	: QObject(parent)
{}

SenterAndRecord::~SenterAndRecord()
{}

void SenterAndRecord::sentFile(QString path)
{
	QFile file(path);
	QFileInfo info(path);
	int fileSize = info.size();
	file.open(QFile::ReadOnly);

	while (!file.atEnd())
	{
		static int num = 0;
		if (num == 0)
		{
			m_tcp->write((char*)&fileSize, 4);
		}
		QByteArray line = file.readLine();
		num += line.size();
		int percent = (num * 100 / fileSize);
		//emit curPercent(percent);
		m_tcp->write(line);
	}

}

void SenterAndRecord::recvFile()
{
	connect(m_tcp, &QTcpSocket::readyRead, this, [=]() {

		QByteArray data = m_tcp->readAll();
		// 解码为字符串
		QString decodedString = QString::fromUtf8(data);

		// 输出解码后的字符串
		qDebug() << "Decoded String: " << decodedString;
	});

}

void SenterAndRecord::sentData(QString data)
{
	QByteArray byteArray = QByteArray::fromStdString(data.toStdString());
	m_tcp->write(byteArray);
}

QString SenterAndRecord::recvData()
{
	connect(m_tcp, &QTcpSocket::readyRead, this, [=]() {

		QByteArray data = m_tcp->readAll();
		// 解码为字符串
		QString decodedString = QString::fromUtf8(data);

		// 输出解码后的字符串
		qDebug() << "Decoded String: " << decodedString << " size = " << decodedString.size();
		emit recvDataFromServer(decodedString);
		return decodedString;
	});
	return "";
}

void SenterAndRecord::connectServer(unsigned short port, QString ip)
{
	m_tcp = new QTcpSocket;
	m_tcp->connectToHost(QHostAddress(ip), port);
	connect(m_tcp, &QTcpSocket::connected, this, &SenterAndRecord::connectOK);

	connect(m_tcp, &QTcpSocket::disconnected, this, [=]() {

		m_tcp->close();
		m_tcp->deleteLater();
		emit gameOver();

	});
	recvData();

}
