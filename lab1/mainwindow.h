#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ErrorMessages.h"
#include "InputLinks.h"
#include "QtForDrawing.h"
#include "DutyManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //figure myFigure;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Scale_clicked();

    void on_LoadModel_clicked();

    void on_Move_clicked();

    void on_Turn_clicked();

private:
    Ui::MainWindow *ui;
};

int DrawAction(Ui::MainWindow* ui);
int CallManager(manager myManager, Ui::MainWindow* ui);

#endif // MAINWINDOW_H
