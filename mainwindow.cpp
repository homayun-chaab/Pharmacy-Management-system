#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
bool found = false;     //cheak medicine existance var

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),  //button 1 add medicine
            this, SLOT(addFun()));
    connect(ui->pushButton_2, SIGNAL(cliked),   // button 2 search medicine
        this, SLOT(searchFun()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList medicines;
QStringList prices;
QStringList totalQuant;

void MainWindow::addFun()   //add new madiciene
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
    QString user_m = ui->lineEdit->text();  //madicine name var
    QString user_q = ui->lineEdit_3->text();    //quantity var

    for(int i = 0; i < medicines.length(); i++) //loop throgh madicines to cheak madicines
    {
        qInfo() << medicines[i];
        if(user_m == medicines[i])
        {
            int quant_int = user_q.toInt();
            int prices_int = totalQuant[i].toInt();
            int totalQuant_int = totalQuant[i].toInt();

            int bill = quant_int * prices_int;
            QString bill_str = QString::number(bill);   //convert bill text to number

            totalQuant_int = totalQuant_int - quant_int;
            totalQuant[i] = QString::number(totalQuant_int);

            QMessageBox::information(this, "Customer Bill",
                                     "Total Bill for " + bill_str + " for " + medicines[i]+
                                     "\n Remaning Quantity: "+ totalQuant[i]);
            break;
        }
    }
    if(!found)  //not found message
    {
        QMessageBox::information(this, "Erorr",
                                 "Invalid Medicine!")           ;

    }
}


