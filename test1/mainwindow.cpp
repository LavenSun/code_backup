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
#include <QSharedMemory>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/ml.hpp"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageLabel = new QLabel(this);
    ui->verticalLayout->addWidget(imageLabel);

    MainWindow::sharedMemory= NULL;
    if (NULL == MainWindow::sharedMemory)
    {
            MainWindow::sharedMemory = new QSharedMemory();
            QString qstrNativeKey = QString("RkWebViewModelSM44");
            MainWindow::sharedMemory->setNativeKey(qstrNativeKey);
    }
    if (!MainWindow::sharedMemory->attach(QSharedMemory::ReadOnly))
    {
    qDebug() << "return";
        return;
    }

    startTimer(100);
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
    Mat A;
    static int time=0;
    time++;
    //qDebug() << "xxx";

    sharedMemory->lock();
    //qDebug() << "\n try to copy";
    int nByte = 480 * 640 * 3;
    A = Mat::zeros(480 ,640 , CV_8UC3);//bufHight,bufWidth
   // qDebug() << "\n copy success0";
    memcpy(A.data, (char*)sharedMemory->constData(), nByte);
    qDebug() << "\n copy success" << time;
    sharedMemory->unlock();
    //sharedMemory->detach();
    A=resize(A, A, Size(320, 240));
    cvtColor(A, A, CV_BGR2RGB);
    QImage image2 = QImage((uchar*)(A.data), A.cols, A.rows, QImage::Format_RGB888);
    imageLabel->setPixmap(QPixmap::fromImage(image2));
    imageLabel->resize(image2.size());
    imageLabel->show();
    return;

    QFile file("/home/jae942/test01/file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);

    while(!in.atEnd())
    {
        QThread::msleep(20);
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
