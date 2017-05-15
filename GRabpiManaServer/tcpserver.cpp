#include "tcpserver.h"
#include <QDebug>
#include <QNetworkProxy>

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    mTcpServer->setProxy(QNetworkProxy::NoProxy);
    if(!mTcpServer->listen(QHostAddress::Any, 6651)) {
        mTcpServer->close();
        qWarning() << "tcp listen error!";
    }

    connect(mTcpServer, &QTcpServer::newConnection, this, &TcpServer::onNewConnection);
}

TcpServer::~TcpServer()
{
    mTcpServer->close();
}

void TcpServer::onNewConnection()
{
    QTcpSocket *tcpSocket = mTcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &TcpServer::onReadDataFromSocket);
    connect(tcpSocket, &QTcpSocket::disconnected, tcpSocket, &QTcpSocket::deleteLater);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &TcpServer::onDisConnected);
    tcpSocket->write("hello client");
    tcpSocket->flush();
    qDebug()<<"connect a client : " << tcpSocket->peerAddress().toString();
}

void TcpServer::onDisConnected()
{
    qDebug() << "one link disconneted";
}

void TcpServer::onReadDataFromSocket()
{
    QTcpSocket *tSocket = static_cast<QTcpSocket*>(sender());
    QByteArray data = tSocket->readAll();
    qDebug() << QString("[Client:%1  %2]").arg(tSocket->peerAddress().toString()).arg(QString(data));
}
