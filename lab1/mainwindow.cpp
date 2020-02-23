#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "InputCoords.h"
#include "DrawingFigure.h"
#include "ScaleFigure.h"
#include "MoveFigure.h"
#include "TurnFigure.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

figure myFigure = Init(); //FIX THIS PLEASE

MainWindow::~MainWindow()
{
    delete ui;
}

void DrawAction(Ui::MainWindow* ui, figure myFigure)
{
    draw drawInfo;

    drawInfo.gV = ui->graphicsView;
    drawInfo.height = ui->graphicsView->height();
    drawInfo.width = ui->graphicsView->width();

    DrawFigure(myFigure, drawInfo);
}

void MainWindow::on_pushButton_3_clicked()
{
    struct move myMove;

    myMove.dx = ui->lineEdit_4->text().toInt();
    myMove.dy = ui->lineEdit_5->text().toInt();
    myMove.dz = ui->lineEdit_6->text().toInt();

    int CodeError = MovePointsArray(myFigure, myMove);

    if (!CodeError)
    {
        DrawAction(ui, myFigure);
    }
}

void MainWindow::on_pushButton_clicked()
{
    scale myScale; //add struct

    myScale.kx = ui->lineEdit->text().toFloat();
    myScale.ky = ui->lineEdit_2->text().toFloat();
    myScale.kz = ui->lineEdit_3->text().toFloat();

    int CodeError = ScalePointsArray(myFigure, myScale);

    if (!CodeError)
    {
        DrawAction(ui, myFigure);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int CodeError = LoadModelFromFile(myFigure, "model.txt");
    if (!CodeError)
    {
        DrawAction(ui, myFigure);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    turn myTurn; //add struct

    myTurn.ox = ui->lineEdit_7->text().toFloat();
    myTurn.oy = ui->lineEdit_8->text().toFloat();
    myTurn.oz = ui->lineEdit_9->text().toFloat();

    int CodeError = TurnPointsArray(myFigure, myTurn);

    if (!CodeError)
    {
        DrawAction(ui, myFigure);
    }

}







