#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "udpclient.h"
#include "tcpclient.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void send();

private:
    Ui::Widget *ui;
    TcpClient *mTcpClient;
};

#endif // WIDGET_H
