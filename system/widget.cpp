#include "widget.h"
#include "ui_widget.h"
#include <fstream>

class person//用户类
{
public:
    char id[20]="\0";
    char password[20]="\0";
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //将密码框设置为隐藏
    ui->password_line->setEchoMode(QLineEdit::Password);
    //四个参数，谁发出信号，发出什么信号，发信号给谁，怎么处理
    //谁发出信号就是ui中的哪个成员
    //发出什么信号可以去类里边找，比如id_line就去/帮助/LineEdit/信号 找
    connect(ui->id_line,SIGNAL(returnPressed()),this,SLOT(switch_line()));
    connect(ui->password_line,SIGNAL(returnPressed()),this,SLOT(on_DownloadButton_clicked()));
    connect(ui->loginButton,&QPushButton::clicked,this,&Widget::on_DownloadButton_clicked);
    connect(ui->canseebox,SIGNAL(stateChanged(int)),this,SLOT(switch_hidepassword()));
}

Widget::~Widget()
{
    delete ui;
}

//账号输入完毕后输入回车将光标切换到密码栏中
void Widget::switch_line()
{
    ui->password_line->setFocus();
}

//隐藏密码
void Widget::switch_hidepassword()
{
    if(ui->canseebox->isChecked())
        ui->password_line->setEchoMode(QLineEdit::Normal);
    else
        ui->password_line->setEchoMode(QLineEdit::Password);
}

//登录账号
void Widget::on_DownloadButton_clicked()
{
    //获取lineedit数据
    QString id = ui->id_line->text();
    QString password = ui->password_line->text();
    if(id.length()==0)
    {
        QMessageBox::information(this,"ERROR!","账号不能为空");
        return;
    }
    else if(password.length()==0)
    {
        QMessageBox::information(this,"ERROR!","密码不能为空");
        return;
    }
    person p;
    std::ifstream ifs;
    ifs.open("D:\\dai ma\\ccc.txt",std::ios::in|std::ios::binary);
    if(!ifs.is_open()) {ifs.close();ifs.open("D:\\dai ma\\ccc.txt",std::ios::out|std::ios::binary);ifs.close();return;}
    while(ifs.read((char*)&p,sizeof(p)))
    {
        if(p.id==id&&p.password==password)
        {
            QMessageBox::information(this,"","登陆成功");
            this->sign=1;
            this->close();

                //注册mainwindow到qwebchannel中
                channel.registerObject(QStringLiteral("mainWindow"), &mainWindow);
                view.page()->setWebChannel(&channel);//html与view进行数据通讯
                view1.page()->setWebChannel(&channel);
                view2.page()->setWebChannel(&channel);
                view3.page()->setWebChannel(&channel);
                view.setUrl(QUrl("D:/code/c/html/myhtml.html"));//打开网页
                view1.setUrl(QUrl("D:/code/c/html/menagement.html"));
                view2.setUrl(QUrl("D:/code/c/html/menagement2.html"));
                view3.setUrl(QUrl("D:/code/c/html/menagement3.html"));
                view.load(QUrl("D:/code/c/html/myhtml.html"));
                view1.load(QUrl("D:/code/c/html/menagement.html"));
                view2.load(QUrl("D:/code/c/html/menagement2.html"));
                view3.load(QUrl("D:/code/c/html/menagement3.html"));
                view.show();
                return;
        }
        else if(p.id==id&&p.password!=password)
        {
            QMessageBox::information(this,"ERROR!","密码错误,请重新输入");
            return;
        }
    }
    if(ifs.eof())
    {
        QMessageBox::information(this,"ERROR!","不存在此账号\n请自行检查后输入");
    }
    ifs.close();
}

//注册账号
void Widget::on_EnrollButton_clicked()
{
    ui->id_line->clear();
    ui->password_line->clear();
    w1=new(EnrollWidget);
    w1->show();
}

// //找回密码
// void Widget::on_RetrieveButton_clicked()
// {
//     ui->password_line->clear();
//     this->w2=new RetrieveForm;
//     w2->init_id(ui->id_line->text());
//     w2->show();
// }
