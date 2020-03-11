#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    manager myManager;
    myManager.currentTask = FREE;
    CallManager(myManager, ui);
    delete ui;
}

void MainWindow::on_LoadModel_clicked()
{
    manager myManager;

    myManager.currentTask = LOAD_FILE;
    myManager.load.filename = ui->InputFileName->text().toStdString().c_str();

    int codeError = CallManager(myManager, ui);
    if (codeError)
        ErrorMessages(codeError);
}

int CallManager(manager myManager, Ui::MainWindow* ui)
{
    int codeError = DutyManager(myManager);

    if (!codeError)
        codeError = DrawAction(ui);

    return codeError;
}

int DrawAction(Ui::MainWindow* ui)
{
    graphView drawInfo;

    drawInfo.graphView = ui->graphicsView;
    drawInfo.height = ui->graphicsView->height();
    drawInfo.width = ui->graphicsView->width();

    manager myManager;

    myManager.currentTask = PAINT;
    myManager.view = drawInfo;

    int codeError = DutyManager(myManager);

    return codeError;
}

void MainWindow::on_Move_clicked()
{
    manager myManager;
    myManager.currentTask = MOVE;

    myManager.move.dx = ui->SpinBoxDxMove->value();
    myManager.move.dy = ui->SpinBoxDyMove->value();
    myManager.move.dz = ui->SpinBoxDzMove->value();

    int codeError = CallManager(myManager, ui);
    if (!codeError)
        ErrorMessages(codeError);
}

void MainWindow::on_Scale_clicked()
{
    manager myManager;
    myManager.currentTask = SCALE;

    myManager.scale.kx = ui->SpinBoxKxScale->value();
    myManager.scale.ky = ui->SpinBoxKyScale->value();
    myManager.scale.kz = ui->SpinBoxKzScale->value();

    int codeError = CallManager(myManager, ui);
    if (!codeError)
        ErrorMessages(codeError);
}

void MainWindow::on_Turn_clicked()
{
    manager myManager;
    myManager.currentTask = TURN;

    myManager.turn.ox = ui->SpinBoxOxTurn->value();
    myManager.turn.oy = ui->SpinBoxOyTurn->value();
    myManager.turn.oz = ui->SpinBoxOzTurn->value();

    int codeError = CallManager(myManager, ui);
    if (codeError)
        ErrorMessages(codeError);
}
