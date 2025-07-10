#ifndef WIDGET_H
#define WIDGET_H

#include <enrollwidget.h>
#include "mainwindow.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int sign=0;
    QWebEngineView view,view1,view2,view3;//创建网页视图
    QWebChannel channel;
    MainWindow mainWindow;

private slots://所有的槽函数声明都要加上slots
    void on_DownloadButton_clicked();
    void on_EnrollButton_clicked();
    void switch_line();
    void switch_hidepassword();

private:
    Ui::Widget *ui;
    EnrollWidget *w1=NULL;//注册子窗口
};

#endif // WIDGET_H
