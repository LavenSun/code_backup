#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <QApplication>
#include <QTime>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    QFile file("/home/jae942/QTDIR/test01/file.txt");
    //    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    //        return;
    //    QTextStream in(&file);
    //QString QTextStream::readLine(qint64 maxlen = 0);
    //    while(!in.atEnd())
    //    {
    //    QString line1 = in.readLine(0);
    //     //QString line1= in.readAll();
    //     qDebug()<<line1;
    //     ui->label1->setText(line1);
    //    }

    startTimer(1000);
    setFont(QFont("Microsoft Yahei", 23));
    QString qss1 = QString("QLabel{background-color:rgb(0,0,0);color:rgb(%1);}").arg("100,184,255");
    QString qss2 = QString("QLabel{background-color:rgb(0,0,0);color:rgb(%1);}").arg("255,107,107");
    QString qss3 = QString("QLabel{background-color:rgb(0,0,0);color:rgb(%1);}").arg("24,189,155");

    ui->label1->setStyleSheet(qss1);
    ui->label2->setStyleSheet(qss2);
    ui->label3->setStyleSheet(qss3);
    connect(ui->radioButton,&QRadioButton::clicked,[=](){
        qDebug() << "控制指令：起飞";
        //control_flag=1;
    });
    connect(ui->radioButton_2,&QRadioButton::clicked,[=](){
        qDebug() << "控制指令：悬停";
        //control_flag=2;
    });
    connect(ui->radioButton_3,&QRadioButton::clicked,[=](){
        qDebug() << "控制指令：识别跟随";
        //control_flag=3;
    });
    connect(ui->radioButton_4,&QRadioButton::clicked,[=](){
        qDebug() << "控制指令：识别打击";
        //control_flag=4;
    });

//    connect(ui->horizontalScrollBar,&QAbstractSlider::sliderPressed(),[=](){
//        qDebug() << ui->horizontalScrollBar->value();
//    })

}
void MainWindow::timerEvent(QTimerEvent *)
{
    QFile file("/home/jae942/test01/file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);

//    while(1){
//}
    while(!in.atEnd())
    {
        sleep(200);
        QString line1 = in.readLine(0);
        //QString line1= in.readAll();
        QString linex = QString("   x轴的速度为%1，加速度为%2").arg(line1).arg(line1);
        qDebug()<<line1;
        ui->label1->setText(linex);
        QString liney = QString("   y轴的速度为%1，加速度为%2").arg(line1).arg(line1);
        ui->label2->setText(liney);
        QString linez = QString("   z轴的速度为%1，加速度为%2").arg(line1).arg(line1);
        ui->label3->setText(linez);
        //time
        QTime *time = new QTime();
        QString timeNote= time->currentTime().toString("hh:mm:ss");
        //qDebug()<<timeNote;
        QString timedisplay = QString("时间：%1").arg(timeNote);
        ui->label4->setText(timedisplay);
    }

}
//获取数字
//int MainWindow::getNum(){

//    return ui->horizontalScrollBar->value();
//}
void MainWindow::sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // 是否按下Ctrl键
    if(event->modifiers() == Qt::ControlModifier)
    {
        // 是否按下M键
        if(event->key() == Qt::Key_M)
            // 窗口最大化
            setWindowState(Qt::WindowMaximized);
    }
    //数据存放
    else if(event->key() == Qt::Key_W)
    {
        RecordOutput[0] = RecordOutput[0] + 1;
        ui->label_6->setText(tr("前进：%1个单位").arg(RecordOutput[0]));
    }
    else if(event->key() == Qt::Key_A)
    {
        RecordOutput[1] = RecordOutput[1] + 1;
        ui->label_7->setText(tr("左移：%1个单位").arg(RecordOutput[1]));
    }
    else if(event->key() == Qt::Key_S)
    {
        RecordOutput[2] = RecordOutput[2] + 1;
        ui->label_8->setText(tr("后退：%1个单位").arg(RecordOutput[2]));
    }
    else if(event->key() == Qt::Key_D)
    {
        RecordOutput[3] = RecordOutput[3] + 1;
        ui->label_9->setText(tr("右移：%1个单位").arg(RecordOutput[3]));
    }
    else if(event->key() == Qt::Key_Up)
    {
        RecordOutput[4] = RecordOutput[4] + 1;
        ui->label_10->setText(tr("上升：%1个单位").arg(RecordOutput[4]));
    }
    else if(event->key() == Qt::Key_Down)
    {
        RecordOutput[5] = RecordOutput[5] + 1;
        ui->label_11->setText(tr("下降：%1个单位").arg(RecordOutput[5] + 3));
        //小键盘的向下按键是从控制指令那一栏开始的，一直移动到“控制指令：识别打击”后才会开始显示下降距离，所以需要+3
    }
    else QWidget::keyPressEvent(event);
}
