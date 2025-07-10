#ifndef ENROLLWIDGET_H
#define ENROLLWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QProcess>

namespace Ui {
class EnrollWidget;
}

class EnrollWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EnrollWidget(QWidget *parent = nullptr);
    ~EnrollWidget();
    int model=0;

private slots://槽函数都要加slots
    bool on_checkpushButton_clicked();
    void on_EnrollpushButton_clicked();
    void switch_line();
    void switch_hidepassword();

private:
    Ui::EnrollWidget *ui;
};

#endif // ENROLLWIDGET_H
