#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
namespace Ui {
class Widget;
}
class Widget :
        public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
    bool keyUp;
    bool keyDown;
    bool keyLeft;
    bool keyRight;
    bool flag;
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};
#endif // WIDGET_H
