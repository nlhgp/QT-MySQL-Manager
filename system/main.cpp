#include "mainwindow.h"
#include <QApplication>
#include <widget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebEngineView view,view1,view2,view3;//创建网页视图
    QWebChannel channel;
    MainWindow mainWindow;
    Widget w;
    //注册mainwindow到qwebchannel中
    // channel.registerObject(QStringLiteral("mainWindow"), &mainWindow);
    // view.page()->setWebChannel(&channel);//html与view进行数据通讯
    // view1.page()->setWebChannel(&channel);
    // view2.page()->setWebChannel(&channel);
    // view3.page()->setWebChannel(&channel);
    // view.load(QUrl("D:/code/c/html/myhtml.html"));//打开网页
    // view1.load(QUrl("D:/code/c/html/menagement.html"));
    // view2.load(QUrl("D:/code/c/html/menagement2.html"));
    // view3.load(QUrl("D:/code/c/html/menagement3.html"));
    // view.show();
    w.show();
    return a.exec();
}
