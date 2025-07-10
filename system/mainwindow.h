#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>//主窗口
#include <QWebEngineView>//web引擎
#include <QtSql/QSqlDatabase>//数据库头文件
#include <qsqlquery.h>//操作数据库对象
#include <qmessagebox.h>//小弹窗
#include <qwebchannel.h>//连接用的
#include <selectbase.h>
#include <insertbase.h>
#include <deletebase.h>
#include <alterbase.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString m;
    selectbase *s;
    menagement *t;
    deletebase *d;
    alterbase  *a;

public slots:
    void receiveMessageFromJS(const QString &message);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
