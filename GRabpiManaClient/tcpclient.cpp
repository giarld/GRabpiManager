#include "tcpclient.h"
#include <QNetworkProxy>
#include <QDebug>

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->setProxy(QNetworkProxy::NoProxy);
    mTcpSocket->abort();
//    mTcpSocket->connectToHost("gxinpim.nat123.net", 33028);
    mTcpSocket->connectToHost("127.0.0.1", 6651);
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &TcpClient::onReadMsg);
}

TcpClient::~TcpClient()
{
    mTcpSocket->close();
}

void TcpClient::sendData(const QString &data)
{
    QByteArray byte;
    byte.append(data);
    sendData(byte);
}

void TcpClient::sendData(const QByteArray &data)
{
    mTcpSocket->write(data);
}

void TcpClient::onReadMsg()
{
    QByteArray msg = mTcpSocket->readAll();
    qDebug() << QString(msg);
}
