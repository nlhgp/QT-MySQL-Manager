#include "deletebase.h"
#include "ui_deletebase.h"

deletebase::deletebase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletebase)
{
    ui->setupUi(this);
    //按下回车换行
    connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(finish()));
    connect(ui->idline, &QLineEdit::returnPressed, this, &deletebase::switch_line);
    connect(ui->nameline,SIGNAL(returnPressed()),this,SLOT(finish()));
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
}

deletebase::~deletebase()
{
    delete ui;
}

void deletebase::get_type(int a)
{
    this->type=a;
    if(a==73)
    {
        ui->title->setText("请输入要删除的id，不知道就去查询");
        ui->namelabel->setVisible(false);
        ui->nameline->setVisible(false);
    }
}

void deletebase::switch_line()
{
    if(focusWidget()==ui->idline) ui->nameline->setFocus();
}

void deletebase::finish()
{
    QSqlQuery query;
    QString sql,id=ui->idline->text(),name=ui->nameline->text();
    switch(this->type)
    {
    case 52:
        sql=QString("delete from base_info where base_id=%1 and base_name='%2';").arg(id).arg(name);
        break;
    case 62:
        sql=QString("delete from user_reservation where user_id=%1 and user_name='%2';").arg(id).arg(name);
        break;
    case 72:
        sql=QString("delete from visit_record where record_id=%1;").arg(id);
        break;
    }
    if(query.exec(sql))
        QMessageBox::information(this,"提示","删除成功");
    else
        QMessageBox::information(this,"ERROR","删除失败");
}

