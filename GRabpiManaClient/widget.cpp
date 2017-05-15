#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &Widget::send);

    mTcpClient = new TcpClient(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::send()
{
    mTcpClient->sendData(ui->lineEdit->text());
}
