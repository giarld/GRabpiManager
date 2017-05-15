#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = 0);
    ~TcpClient();

    void sendData(const QString &data);
    void sendData(const QByteArray &data);

signals:

public slots:
    void onReadMsg();

private:
    QTcpSocket *mTcpSocket;
};

#endif // TCPCLIENT_H
