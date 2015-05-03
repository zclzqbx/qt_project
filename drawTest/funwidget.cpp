#include "funwidget.h"
#include <QPainter>
#include <QPoint>
#include <math.h>

double fsin(double x)//三个函数
{
    return sin(x);
}

double fex(double x)
{
    return exp(x);
}
double fnord(double x)
{
    const int pi=3.14159;
    return (1/sqrt(2*pi))*exp(-x*x/2);
}

FunWidget::FunWidget(QWidget *parent) :
    QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMinimumSize(400,400);
    pen.setColor(Qt::red);
}

void FunWidget::setFunction(Function f)//四个参数
{
    function=f;
    update();
}

void FunWidget::setPen(QPen p)
{
    pen=p;
    update();
}

void FunWidget::setWidth(int w)
{
    width=w;
    update();
}

void FunWidget::setColor(QColor c)
{
    color=c;
    update();
}

void FunWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    pen.setColor(color);
    pen.setWidth(width);
    painter.setPen(pen);


    switch(function)//调用函数构建Path
    {
        case Sin:
            fpoint=fsin;break;
        case Ex:
            fpoint=fex;break;
        case NorD:
            fpoint=fnord;break;
        default:break;
    }

    painter.drawLine(geometry().x(),geometry().height()/2,geometry().width(),geometry().height()/2);
    painter.drawLine(geometry().x(),geometry().height(),geometry().x(),geometry().y());//绘制坐标轴，有待完善

    QPainterPath path;
    const int Num=1000;//这两个可以作为成员变量
    const int Min=0,Max=100;
    const int distance=(Max-Min)/Num;
    double x(0),y=fpoint(x);
    for(int i=0;i<Num;++i)
    {
        int forex=x,forey=y;
        path.moveTo(forex,forey);
        x=x+distance*i;
        y=fpoint(x);
        path.lineTo(x,y);
    }
    painter.drawPath(path);

}













