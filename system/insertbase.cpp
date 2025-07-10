#include "insertbase.h"
#include "ui_insertbase.h"

menagement::menagement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menagement)
{
    ui->setupUi(this);
    //某一行输入完按下回车切换到下一行
    connect(ui->lineEdit_1,SIGNAL(returnPressed()),this,SLOT(on_lineEdit_editingFinished()));
    connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(on_lineEdit_editingFinished()));
    connect(ui->lineEdit_3,SIGNAL(returnPressed()),this,SLOT(on_lineEdit_editingFinished()));
    connect(ui->lineEdit_4,SIGNAL(returnPressed()),this,SLOT(on_lineEdit_editingFinished()));
    connect(ui->lineEdit_5,SIGNAL(returnPressed()),this,SLOT(on_lineEdit_editingFinished()));
    connect(ui->lineEdit_6,SIGNAL(returnPressed()),this,SLOT(on_lineEdit_editingFinished()));
    connect(ui->lineEdit_7,SIGNAL(returnPressed()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton,SIGNAL(clicked),this,SLOT(on_pushButton_clicked()));
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
        this->close();
    }
}

menagement::~menagement()
{
    delete ui;
}

void menagement::on_lineEdit_editingFinished()
{
    if(focusWidget()==ui->lineEdit_1) ui->lineEdit_2->setFocus();
    else if(focusWidget()==ui->lineEdit_2) ui->lineEdit_3->setFocus();
    else if(focusWidget()==ui->lineEdit_3) ui->lineEdit_4->setFocus();
    else if(focusWidget()==ui->lineEdit_4) ui->lineEdit_5->setFocus();
    else if(focusWidget()==ui->lineEdit_5) ui->lineEdit_6->setFocus();
    else if(focusWidget()==ui->lineEdit_6) ui->lineEdit_7->setFocus();
}


void menagement::get_model(int a)//处理窗口
{
    this->model=a;
    switch(model)//设置隐藏构件，就不用再多建那么多窗口了
    {
    case 51:
       ui->title->setText("新增教育基地");break;
       ui->title->setAlignment(Qt::AlignCenter);
       ui->label_3->setText("地名");
       ui->label_4->setText("地址");
       ui->label_5->setText("开棺时间");
       ui->label_6->setText("闭馆时间");
       ui->label_7->setText("介绍");
       ui->label_8->setText("主题");
       q->setTable("base_info");//打开表格
    case 61:
        ui->title->setText("新增用户信息");
        ui->title->setAlignment(Qt::AlignCenter);
        ui->label_8->setVisible(false);
        ui->lineEdit_7->setVisible(false);
        q->setTable("user_reservation");
        break;
    case 71:
        ui->title->setText("新增预约信息");
        ui->label_3->setText("基地编号");
        ui->label_4->setText("用户编号");
        ui->label_5->setText("访问日期");
        ui->label_6->setText("duration");
        ui->label_8->setVisible(false);
        ui->lineEdit_7->setVisible(false);
        ui->lineEdit_6->setVisible(false);
        ui->label_7->setVisible(false);
        q->setTable("visit_record");
        break;
    }
}

void menagement::on_pushButton_clicked()
{
    QSqlQuery query;
    QString sql;
    switch(this->model)
    {
    case 51:
        sql=QString("insert into base_info values (%1,'%2','%3','%4','%5','%6','%7');").arg(ui->lineEdit_1->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->lineEdit_6->text()).arg(ui->lineEdit_7->text());
        break;
    case 61:
        sql=QString("insert into user_reservation values (%1,'%2','%3',%4,'%5','%6');").arg(ui->lineEdit_1->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->lineEdit_6->text());
        break;
    case 71:
        sql=QString("insert into visit_record values (%1,%2,%3,'%4','%5');").arg(ui->lineEdit_1->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text());
        break;
    }
    if(query.exec(sql))
        QMessageBox::information(this,"提示","插入成功");
    else
        QMessageBox::information(this,"ERROR","插入失败");
}
