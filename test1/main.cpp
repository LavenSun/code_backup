#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include<QSharedMemory>
#include "mythread.h"
#include "ctrlthread.h"
#include <QDebug>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/ml.hpp"

using namespace cv;

int main(int argc, char *argv[])
{
    myThread *thread1 = new myThread; //新建线程对象
    ctrlThread *thread2 = new ctrlThread; //新建线程对象
    thread1->start();
    thread2->start();
    QThread::sleep(10);
    qDebug() << "sleeped";
/*
    QSharedMemory* sharedMemory = NULL;
    if (NULL == sharedMemory)
        {
            sharedMemory = new QSharedMemory();
            QString qstrNativeKey = QString("RkWebViewModelSM4");
            sharedMemory->setNativeKey(qstrNativeKey);
        }
    if (!sharedMemory->attach(QSharedMemory::ReadOnly))
    {
        //QMessageBox::information(this, "", "attach failed!");
        //return 0;
    }

    sharedMemory->lock();
    int nByte = 480 * 640 * 3;
    Mat cvoutImg = Mat::zeros(480 ,640 , CV_8UC3);//bufHight,bufWidth
    memcpy(cvoutImg.data, (char*)sharedMemory->constData(), nByte);
    qDebug() << "\n copy success";
    sharedMemory->unlock();
    sharedMemory->detach();
*/



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
