#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QPalette pa;
    ui->setupUi(this);
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->label->setPalette(pa);
    //setFocus();
    flag=1;
    /* 看是否使用isAutoRepeat */
    keyUp=false;
    keyLeft=false;
    keyRight=false;
    keyDown=false;
    ui->pushButton->move(180,130);
    /* set middle point */
}
Widget::~Widget()
{
    delete ui;
}
void Widget::keyPressEvent(QKeyEvent *event){}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    static int offset_x=0,offset_y=0;
    flag =ui->checkBox->isChecked();
    if(event->key() == Qt::Key_Up)
    {
        if(event->isAutoRepeat()&&(flag==0))
            return;
        if(offset_x==0)
        {
            offset_y=offset_y-10;
            if(offset_y<-100)
                offset_y=-100;
            ui->pushButton->move(180+offset_x,130+offset_y);
        }
    }
    if(event->key() == Qt::Key_Down)
    {
        if(event->isAutoRepeat()&&(flag==0))
            return;
        if(offset_x==0)
        {
            offset_y=offset_y+10;
            if(offset_y>100)
                offset_y=100;
            ui->pushButton->move(180+offset_x,130+offset_y);
        }
    }
    if(event->key() == Qt::Key_Left)
    {
        if(event->isAutoRepeat()&&(flag==0))
            return;
        if(offset_y==0)
        {
            offset_x=offset_x-10;
            if(offset_x<-100)
                offset_x=-100;
            ui->pushButton->move(180+offset_x,130+offset_y);
        }
    }
    if(event->key() == Qt::Key_Right)
    {
        if(event->isAutoRepeat()&&(flag==0))
            return;
        if(offset_y==0)
        {
            offset_x=offset_x+10;
            if(offset_x>100)
                offset_x=100;
            ui->pushButton->move(180+offset_x,130+offset_y);
        }
    }
}
