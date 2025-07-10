#ifndef DELETEBASE_H
#define DELETEBASE_H

#include <QWidget>
#include <QSqlQuery>//操作数据库的对象
#include <QSqlTableModel>//显示数据库信息的对象
#include <qmessagebox.h>


namespace Ui {
class deletebase;
}

class deletebase : public QWidget
{
    Q_OBJECT

public:
    explicit deletebase(QWidget *parent = nullptr);
    ~deletebase();
    QSqlTableModel *q;
    QSqlDatabase db;
    int type;
    void switch_line();
    void get_type(int a);

private slots:
    void finish();

private:
    Ui::deletebase *ui;
};

#endif // DELETEBASE_H
