#include "udpserver.h"
#include <QByteArray>
#include <QDebug>

UdpServer::UdpServer(QObject *parent) : QObject(parent)
{
    mUdpSocket = new QUdpSocket(this);
    mUdpSocket->bind(QHostAddress::Any, 6650);
    connect(mUdpSocket, &QUdpSocket::readyRead, this, &UdpServer::udpReadPendingDatagrams);
}

UdpServer::~UdpServer()
{
    mUdpSocket->close();
}

void UdpServer::udpReadPendingDatagrams()
{
    while(mUdpSocket->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(mUdpSocket->pendingDatagramSize());
        mUdpSocket->readDatagram(data.data(), data.size());
        qDebug() << QString(data);
    }
}
