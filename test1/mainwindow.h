#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include<QSharedMemory>
#include <QThread>
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

private:
    Ui::MainWindow *ui;
    void timerEvent(QTimerEvent *);
    void sleep(unsigned int msec);
    QSharedMemory* sharedMemory;
        QLabel *imageLabel;
};

#endif // MAINWINDOW_H
