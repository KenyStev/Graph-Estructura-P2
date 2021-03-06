#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GraphGraph *graph = new GraphGraph(true);
    graph->setWindowTitle("Grafos Dirigidos");
    graph->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    GraphGraph *graph = new GraphGraph(false);
    graph->setWindowTitle("Grafos No Dirigidos");
    graph->show();
}

void MainWindow::on_btnSorts_clicked()
{
    Sorts *sorts = new Sorts();
    sorts->setWindowTitle("Sorts");
    sorts->show();
}
