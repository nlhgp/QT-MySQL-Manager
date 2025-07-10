#ifndef ALTERBASE_H
#define ALTERBASE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>//操作数据库的对象
#include <QSqlTableModel>//显示数据库信息的对象
#include <qmessagebox.h>//小弹窗

namespace Ui {
class alterbase;
}

class alterbase : public QWidget
{
    Q_OBJECT

public:
    explicit alterbase(QWidget *parent = nullptr);
    ~alterbase();
    int model;
    void get_model(int a);
    void switch_line();

private slots:
    void on_pushButton_clicked();

private:
    Ui::alterbase *ui;
    QSqlTableModel *q;//用于显示数据库信息
    QSqlDatabase db;
};

#endif // ALTERBASE_H
