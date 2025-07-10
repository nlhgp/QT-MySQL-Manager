#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::receiveMessageFromJS(const QString &message)
{
    if(message=="01")
    {}
    else if(message == "02")//查询
    {
        s=new selectbase;
        s->get_type(2);
        s->show();
    }
    else if(message == "03")
    {
        s=new selectbase;
        s->get_type(3);
        s->show();
    }
    else if(message == "04")
    {
        s=new selectbase;
        s->get_type(4);
        s->show();
    }
    else if(message=="51")//插入
    {
        t=new menagement;
        t->get_model(51);
        t->show();
    }
    else if(message == "61")
    {
        t=new menagement;
        t->get_model(61);
        t->show();
    }
    else if (message == "71")
    {
        t=new menagement;
        t->get_model(71);
        t->show();
    }
    else if(message == "52")//删除
    {
        d=new deletebase;
        d->get_type(52);
        d->show();
    }
    else if(message == "62")
    {
        d=new deletebase;
        d->get_type(62);
        d->show();
    }
    else if(message == "72")
    {
        d=new deletebase;
        d->get_type(72);
        d->show();
    }
    else if(message == "53")
    {
        a=new alterbase;
        a->get_model(53);
        a->show();
    }
    else if(message == "63")
    {
        a=new alterbase;
        a->get_model(63);
        a->show();
    }
    else if(message == "73")
    {
        a=new alterbase;
        a->get_model(73);
        a->show();
    }
    qDebug() << message << " ";
}

MainWindow::~MainWindow()
{
    delete ui;
    delete s;
}
