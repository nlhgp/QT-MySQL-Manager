#include "enrollwidget.h"
#include "ui_enrollwidget.h"
#include<fstream>

class person//用户类
{
public:
    char id[20]="\0";
    char password[20]="\0";
};

EnrollWidget::EnrollWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EnrollWidget)
{
    ui->setupUi(this);
    //将密码框设置成隐藏模式
    ui->passwordlineEdit->setEchoMode(QLineEdit::Password);
    ui->againlineEdit->setEchoMode(QLineEdit::Password);
    //连接信号与槽
    //点击‘检测是否可用’则调用on_checkpushButton_clicked()
    connect(ui->checkpushButton,SIGNAL(clicked),this,SLOT(on_checkpushButton_clicked()));
    //在行输入框内按回车就转到下一行，最后一行按下回车后就直接视为点击注册
    connect(ui->idlineEdit,SIGNAL(returnPressed()),this,SLOT(switch_line()));
    connect(ui->passwordlineEdit,SIGNAL(returnPressed()),this,SLOT(switch_line()));
    connect(ui->againlineEdit,SIGNAL(returnPressed()),this,SLOT(on_EnrollpushButton_clicked()));
    //按下注册键即开始注册
    connect(ui->FinishEnroll, &QPushButton::clicked,this, &EnrollWidget::on_EnrollpushButton_clicked);
    //勾选可见后显示密码
    connect(ui->canseebox,SIGNAL(stateChanged(int)),this,SLOT(switch_hidepassword()));
}

EnrollWidget::~EnrollWidget()
{
    delete ui;
}

//隐藏密码
void EnrollWidget::switch_hidepassword()
{
    if(ui->canseebox->isChecked())
    {
        ui->passwordlineEdit->setEchoMode(QLineEdit::Normal);
        ui->againlineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->passwordlineEdit->setEchoMode(QLineEdit::Password);
        ui->againlineEdit->setEchoMode(QLineEdit::Password);
    }
}

//注册账号
void EnrollWidget::on_EnrollpushButton_clicked()
{
    this->model=2;
    if(!(this->on_checkpushButton_clicked()))//先检查一遍，如果有问题就直接返回
        return;
    else if(ui->passwordlineEdit->text().length()==0)
    {
        QMessageBox::information(this,"ERROR!","密码不能为空");
        return;
    }
    std::ofstream ofs("D:\\dai ma\\ccc.txt",std::ios::app|std::ios::binary);
    //从账号文本框获取字符串
    QString s=ui->idlineEdit->text();
    std::string str=s.toStdString();//转化成std::string
    person p;//工具人
    int i;//工具i
    for(i=0;i<20;++i)
    {p.id[i]=str[i];}
    //从密码文本框获取字符串
    s=ui->passwordlineEdit->text();
    str=s.toStdString();
    for(i=0;i<20;++i)
    {p.password[i]=str[i];}
    ofs.write((char*)&p,sizeof(person));
    QMessageBox::information(this,"","注册成功！");
    this->close();
}

//按下回车后切换输入框
void EnrollWidget::switch_line()
{
    //在账号框按回车就跳到密码框
    if(focusWidget()==ui->idlineEdit)
    {
        ui->passwordlineEdit->setFocus();
    }
    //在密码框按回车就跳到重复框
    else if(focusWidget()==ui->passwordlineEdit)
    {
        ui->againlineEdit->setFocus();
    }
}

//检查账号是否已注册
bool EnrollWidget::on_checkpushButton_clicked()
{
    std::ifstream ifs;
    person p;
    QString s=ui->idlineEdit->text();//获取输入框中文本
    if(ui->idlineEdit->text().length()==0)
    {
        QMessageBox::information(this,"ERROR!","账号不能为空");
        return false;
    }
    if(ui->passwordlineEdit->text() != ui->againlineEdit->text())
    {
        QMessageBox::information(this,"ERROR!","两次输入密码不一致！");
        return false;
    }
    ifs.open("D:\\dai ma\\ccc.txt",std::ios::in|std::ios::binary);
    while(ifs.read((char*)&p,sizeof(p)))
    {
        if(s==p.id)
        {
            QMessageBox::information(this,"ERROR!","账号已注册\n请重新输入账号");
            return false;
        }
    }
    if(this->model!=2) QMessageBox::information(this,"","账号未注册\n该账号可用");
    else this->model=1;
    return true;
}

