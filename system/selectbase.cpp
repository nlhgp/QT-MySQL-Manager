#include "selectbase.h"
#include "ui_selectbase.h"
#include <QtSql/QSqlDatabase>//数据库头文件
#include <qsqlquery.h>
#include <qmessagebox.h>

selectbase::selectbase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::selectbase)
{
    ui->setupUi(this);

    //连接数据库
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("sb");//设置打开system_database
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("159357");

    if(db.open())//检测是否连接成功
    {
        //QMessageBox::information(this,"连接提示","连接成功");
        q=new QSqlTableModel;
    }
    else
    {
        QMessageBox::warning(this,"连接提示","连接失败");
    }

    connect(ui->pushButton,SIGNAL(clicked),this,SLOT(on_pushButton_clicked()));
}

selectbase::~selectbase()
{
    delete ui;
    delete q;
}

void selectbase::get_type(int a)
{
    this->type=a;
}

//按下按钮开始查询
void selectbase::on_pushButton_clicked()
{
    if(this->type==2)
        q->setTable("base_info");//打开表格
    else if(this->type==3)
        q->setTable("user_reservation");
    else if(this->type==4)
        q->setTable("visit_record");
    ui->tableView->setModel(q);
    q->select();
}

