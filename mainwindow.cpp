#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(addFun()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList medicines;
QStringList prices;
QStringList totalQuant;

void MainWindow::addFun()
{
    QString medicine = ui->lineEdit->text();
    QString price = ui->lineEdit_2->text();
    QString quant = ui->lineEdit_2->text();

    medicines.append(medicine);
    prices.append(price);
    totalQuant.append(quant);



}

