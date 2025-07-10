#include "alterbase.h"
#include "ui_alterbase.h"

alterbase::alterbase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::alterbase)
{
    ui->setupUi(this);
    //某一行输入完按下回车切换到下一行
    connect(ui->idline, &QLineEdit::returnPressed, this, &alterbase::switch_line);
    connect(ui->lineEdit_1, &QLineEdit::returnPressed, this, &alterbase::switch_line);
    connect(ui->lineEdit_2, &QLineEdit::returnPressed, this, &alterbase::switch_line);
    connect(ui->lineEdit_3, &QLineEdit::returnPressed, this, &alterbase::switch_line);
    connect(ui->lineEdit_4, &QLineEdit::returnPressed, this, &alterbase::switch_line);
    connect(ui->lineEdit_5, &QLineEdit::returnPressed, this, &alterbase::switch_line);
    connect(ui->lineEdit_6, &QLineEdit::returnPressed, this, &alterbase::on_pushButton_clicked);
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

void alterbase::switch_line()
{
    if(focusWidget()==ui->idline) ui->lineEdit_1->setFocus();
    else if(focusWidget()==ui->lineEdit_1) ui->lineEdit_2->setFocus();
    else if(focusWidget()==ui->lineEdit_2) ui->lineEdit_3->setFocus();
    else if(focusWidget()==ui->lineEdit_3) ui->lineEdit_4->setFocus();
    else if(focusWidget()==ui->lineEdit_4) ui->lineEdit_5->setFocus();
    else if(focusWidget()==ui->lineEdit_5) ui->lineEdit_6->setFocus();
}

alterbase::~alterbase()
{
    delete ui;
}

void alterbase::get_model(int a)
{
    this->model=a;
    switch(a)
    {
    case 53:
        ui->label_2->setText("地名");
        ui->label_3->setText("地址");
        ui->label_4->setText("开棺时间");
        ui->label_5->setText("闭馆时间");
        ui->label_6->setText("介绍");
        ui->label_7->setText("主题");
        break;
    case 63:
        ui->label_7->setVisible(false);
        ui->lineEdit_6->setVisible(false);
        break;
    case 73:
        ui->label_2->setText("基地编号");
        ui->label_3->setText("用户编号");
        ui->label_4->setText("访问日期");
        ui->label_5->setText("duration");
        ui->label_6->setVisible(false);
        ui->lineEdit_5->setVisible(false);
        ui->lineEdit_6->setVisible(false);
        ui->label_7->setVisible(false);
        break;
    }
}

void alterbase::on_pushButton_clicked()
{
    QSqlQuery query;
    QString sql;
    switch(this->model)
    {
    case 53:
        sql=QString("update base_info set base_name = '%1', base_address='%2',open_time='%3',close_time='%4',base_description='%5',patriotic_theme='%6' where base_id = %7;").arg(ui->lineEdit_1->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->lineEdit_6->text()).arg(ui->idline->text());
        break;
    case 63:
        sql=QString("update user_reservation set user_name = '%1',user_gender='%2',user_age = %3,contact_info ='%4',reservation_times=%5 where user_id = %6;").arg(ui->lineEdit_1->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->idline->text());
        break;
    case 73:
        sql=QString("update visit_record set base_id = %1,user_id=%2,user_id='%3',visit_duration='%4' where record_id = %5;").arg(ui->lineEdit_1->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->idline->text());
        break;
    }
    if(query.exec(sql))
        QMessageBox::information(this,"提示","修改成功");
    else
        QMessageBox::information(this,"ERROR","修改失败");
}

