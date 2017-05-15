#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QByteArray>

class UdpClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = 0);
    ~UdpClient();

    void sendData(const QString &data);
    void sendData(const QByteArray &data);

private:
    QUdpSocket *mUdpSocket;
};

#endif // UDPCLIENT_H
