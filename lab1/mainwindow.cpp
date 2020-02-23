#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "InputCoords.h"
#include "DrawingFigure.h"
#include "ScaleFigure.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

figure myFigure = Init(); //FIX THIS PLEASE

void DrawAction(Ui::MainWindow* ui, figure myFigure)
{
    draw drawInfo;

    drawInfo.gV = ui->graphicsView;
    drawInfo.height = ui->graphicsView->height();
    drawInfo.width = ui->graphicsView->width();

    DrawFigure(myFigure, drawInfo);
}


void MainWindow::on_pushButton_clicked()
{
    //ui->graphicsView->scene->addLine(x1, y1, x2, y2, a.pen);
}

void MainWindow::on_pushButton_2_clicked()
{
    int CodeError = LoadModelFromFile(myFigure, "model.txt");
    if (!CodeError)
    {
        DrawAction(ui, myFigure);
    }
}
