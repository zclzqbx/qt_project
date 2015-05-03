#ifndef FUNWIDGET_H
#define FUNWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPen>
#include <QColor>

class FunWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FunWidget(QWidget *parent = 0);
    enum Function{Sin,Ex,NorD};
    typedef double (*Fpoint)(double x);

    void setFunction(Function);
    void setPen(QPen);
    void setColor(QColor);
    void setWidth(int);
    void paintEvent(QPaintEvent *);


    
signals:
    
public slots:
    
private:
    Function function;
    QPen pen;
    Fpoint fpoint;
    int width;
    QColor color;
};

#endif // FUNWIDGET_H
