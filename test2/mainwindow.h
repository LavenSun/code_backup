#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    //获取数字
//    int getNum();
    int RecordOutput[6] = {0};

private:
    Ui::MainWindow *ui;
    void timerEvent(QTimerEvent *);
    void sleep(unsigned int msec);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
