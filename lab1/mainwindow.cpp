#include "ErrorMessages.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "InputCoords.h"
#include "QtForDrawing.h"
#include "ScaleFigure.h"
#include "MoveFigure.h"
#include "TurnFigure.h"
#include "LoadModel.h"
#include "AllocateMemory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    PointsFree(myFigure.points, myFigure.links);
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

void MainWindow::on_Move_clicked()
{
    struct move myMove;

    myMove.dx = ui->SpinBoxDxMove->value();
    myMove.dy = ui->SpinBoxDyMove->value();
    myMove.dz = ui->SpinBoxDzMove->value();

    int codeError = MovePointsArray(myFigure, myMove);

    if (!codeError)
        DrawAction(ui, myFigure);
    else
        ErrorMessages(codeError);
}

void MainWindow::on_Scale_clicked()
{
    scale myScale;

    myScale.kx = ui->SpinBoxKxScale->value();
    myScale.ky = ui->SpinBoxKyScale->value();
    myScale.kz = ui->SpinBoxKzScale->value();

    int codeError = ScalePointsArray(myFigure, myScale);

    if (!codeError)
        DrawAction(ui, myFigure);
    else
        ErrorMessages(codeError);
}

void MainWindow::on_LoadModel_clicked()
{
    myFigure = Init(myFigure);

    QString text = ui->InputFileName->text();
    std::string str = text.toStdString();

    int codeError = LoadModelFromFile(myFigure, str.c_str());

    if (!codeError)
        DrawAction(ui, myFigure);
    else
        ErrorMessages(codeError);
}

void MainWindow::on_Turn_clicked()
{
    turn myTurn;

    myTurn.ox = ui->SpinBoxOxTurn->value();
    myTurn.oy = ui->SpinBoxOyTurn->value();
    myTurn.oz = ui->SpinBoxOzTurn->value();

    int codeError = TurnPointsArray(myFigure, myTurn);

    if (!codeError)
        DrawAction(ui, myFigure);
    else
        ErrorMessages(codeError);
}
