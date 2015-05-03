#include "mainwindow.h"
#include <QPixmap>
#include <QColor>
#include <QColorDialog>
#include "funwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(600,400);
    setWindowTitle(tr("Function"));
    toolbar=addToolBar("Tool");

    colorBtn=new QToolButton;
    colorLabel=new QLabel(tr("Color"));
    toolbar->addWidget(colorLabel);
    toolbar->addWidget(colorBtn);
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));

    LineStyle=new QLabel(tr("   Line Style:"));
    LineStyleComboBox=new QComboBox;
    LineStyleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    LineStyleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    LineStyleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    LineStyleComboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    toolbar->addWidget(LineStyle);
    toolbar->addWidget(LineStyleComboBox);
    connect(LineStyleComboBox,SIGNAL(activated(int)),this,SLOT(showLineStyle()));


    FunctionLabel=new QLabel("   Function Label ");
    FunCtionComboBox=new QComboBox;
    FunCtionComboBox->addItem(tr("Sin"),FunWidget::Sin);
    FunCtionComboBox->addItem(tr("Ex"),FunWidget::Ex);
    FunCtionComboBox->addItem(tr("Nord"),FunWidget::NorD);
    toolbar->addWidget(FunctionLabel);
    toolbar->addWidget(FunCtionComboBox);
    connect(FunCtionComboBox,SIGNAL(activated(int)),this,SLOT(showFunction()));

    widthLabel=new QLabel(tr("  Width"));
    widthSpinBox=new QSpinBox;
    widthSpinBox->setRange(0,20);
    toolbar->addWidget(widthLabel);
    toolbar->addWidget(widthSpinBox);
    connect(widthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(showWidth()));

    funWidget=new FunWidget;
    layout=new QGridLayout;
    layout->addWidget(funWidget);

}

MainWindow::~MainWindow()
{

    
}

void MainWindow::showColor()
{
    QColor color=QColorDialog::getColor(static_cast<int>(Qt::black),this);
    if(color.isValid())
    {
        QPixmap pixmap(20,20);
        pixmap.fill(color);
        colorBtn->setIcon(pixmap);

    }
}

void MainWindow::showLineStyle()
{

}

void MainWindow::showFunction()
{

}

void MainWindow::showWidth()
{

}
