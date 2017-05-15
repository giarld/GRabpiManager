#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    ~TcpServer();

signals:

public slots:
    void onNewConnection();
    void onDisConnected();

    void onReadDataFromSocket();

private:
    QTcpServer *mTcpServer;
};

#endif // TCPSERVER_H
