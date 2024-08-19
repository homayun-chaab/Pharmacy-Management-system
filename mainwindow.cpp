#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(addFun()));
    connect(ui->pushButton_2, SIGNAL(cliked),
        this, SLOT(searchFun()));
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

    QMessageBox::information(this, "Sucessful",
                             "Medicine Added Successfully");







}


void MainWindow::searchFun()
{
    QString user_m = ui->lineEdit->text()    ;
    QString user_q = ui->lineEdit_3->text();

    for(int i = 0; i < medicines.length(); i++)
    {
        if(user_m == medicines[i])
        {
            int quant_int = user_q.toInt();
            int prices_int = totalQuant[i].toInt();
            int totalQuant_int = totalQuant[i].toInt();

            int bill = quant_int * prices_int;
            totalQuant[i] = QString::number(totalQuant_int);
        }
    }
}

