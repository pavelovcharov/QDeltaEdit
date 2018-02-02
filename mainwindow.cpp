#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->setDelta(0.2, 1);


    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    ui->tableWidget->setItem(0, 0, item);
    QDeltaEdit* deltaEdit = new QDeltaEdit();
    deltaEdit->setDelta(0.1, 1);
    ui->tableWidget->setCellWidget(0, 0, deltaEdit);

    item = new QTableWidgetItem();
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    ui->tableWidget->setItem(0, 1, item);
    deltaEdit = new QDeltaEdit();
    deltaEdit->setDelta(0.8, 1);
    ui->tableWidget->setCellWidget(0, 1, deltaEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
