#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include "funwidget.h"
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void showColor();
    void showLineStyle();
    void showFunction();
    void showWidth();

private:
    QToolBar *toolbar;
    QLabel *colorLabel;
    QToolButton *colorBtn;
    QLabel *LineStyle;
    QComboBox *LineStyleComboBox;
    QLabel *FunctionLabel;
    QComboBox *FunCtionComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    FunWidget *funWidget;
    QGridLayout *layout;
};

#endif // MAINWINDOW_H
