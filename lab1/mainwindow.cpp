#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "InputCoords.h"
#include "QtForDrawing.h"
#include "ScaleFigure.h"
#include "MoveFigure.h"
#include "TurnFigure.h"
#include "LoadModel.h"

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

    drawInfo.graphView = ui->graphicsView;
    drawInfo.height = ui->graphicsView->height();
    drawInfo.width = ui->graphicsView->width();

    DrawFigure(myFigure, drawInfo);
}

void MainWindow::on_pushButton_3_clicked()
{
    struct move myMove;

    myMove.dx = ui->SpinBoxDxMove->value();
    myMove.dy = ui->SpinBoxDyMove->value();
    myMove.dz = ui->SpinBoxDzMove->value();

    int CodeError = MovePointsArray(myFigure, myMove);

    if (!CodeError)
    {
        DrawAction(ui, myFigure);
    }
}

void MainWindow::on_pushButton_clicked()
{
    scale myScale; //add struct

    myScale.kx = ui->SpinBoxKxScale->value();
    myScale.ky = ui->SpinBoxKyScale->value();
    myScale.kz = ui->SpinBoxKzScale->value();

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
    turn myTurn;

    myTurn.ox = ui->SpinBoxOxTurn->value();
    myTurn.oy = ui->SpinBoxOyTurn->value();
    myTurn.oz = ui->SpinBoxOzTurn->value();

    int CodeError = TurnPointsArray(myFigure, myTurn);

    if (!CodeError)
    {
        DrawAction(ui, myFigure);
    }

}
