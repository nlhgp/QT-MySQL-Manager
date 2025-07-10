#ifndef SELECTBASE_H
#define SELECTBASE_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class selectbase;
}

class selectbase : public QWidget
{
    Q_OBJECT

public:
    explicit selectbase(QWidget *parent = nullptr);
    ~selectbase();
    QSqlTableModel *q;//用于显示sql信息
    void get_type(int a);

private slots:
    void on_pushButton_clicked();

private:
    Ui::selectbase *ui;
    QSqlDatabase db;
    int type;
};

#endif // SELECTBASE_H
