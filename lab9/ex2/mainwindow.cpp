#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    if(QMessageBox::question(this, "What?", "close?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes){
       QApplication::quit();

    }
    else show();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(QMessageBox::question(this, "What?", "close?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes){
       QApplication::quit();

    }
    else show();
}

