#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
class myThread: public QThread
{
public:
    myThread();
    void run(); //声明继承于QThread虚函数 run()
};

#endif // THREADFROMQTHREAD_H
