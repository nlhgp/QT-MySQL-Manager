#ifndef INSERT_H
#define INSERT_H

#include <QWidget>
#include <QSqlQuery>//操作数据库的对象
#include <QSqlTableModel>//显示数据库信息的对象
#include <qmessagebox.h>

namespace Ui {
class menagement;
}

class menagement : public QWidget
{
    Q_OBJECT

public:
    explicit menagement(QWidget *parent = nullptr);
    ~menagement();
    QSqlTableModel *q;//用于显示数据库信息
    int model;
    void get_model(int a);

private slots:
    void on_lineEdit_editingFinished();
    void on_pushButton_clicked();

private:
    Ui::menagement *ui;
    QSqlDatabase db;
};

#endif // INSERT_H
