#include "udpclient.h"
#include <QDebug>

UdpClient::UdpClient(QObject *parent) : QObject(parent)
{
    mUdpSocket = new QUdpSocket(this);
}

UdpClient::~UdpClient()
{
    mUdpSocket->close();
}

void UdpClient::sendData(const QString &data)
{
    QByteArray byte;
    byte.append(data);
    sendData(byte);
}

void UdpClient::sendData(const QByteArray &data)
{
    QHostAddress serverAddress = QHostAddress("115.28.79.163");
//    QHostAddress serverAddress = QHostAddress::Broadcast;
    if(mUdpSocket->writeDatagram(data.data(), data.size(), serverAddress, 33028) == -1) {
        qDebug() << "send fail";
    } else {
        qDebug() << "send success";
    }
}
