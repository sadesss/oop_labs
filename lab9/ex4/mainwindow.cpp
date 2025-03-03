#include "mainwindow.h"
#include "./ui_mainwindow.h"
short num = 0;
QString this_word = "";

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
    QString str;
    str = ui->input->toPlainText();
    if (str != this_word){
        this_word = str;
        num = 0;
    }
    if (num == 0){
        ui->output->setText("Исходный: "+ str);
    }
    num++;
    if (num == 1){
        ui->output->append("Строчные: " + str.toLower());
    }else if (num == 2)
        ui->output->append("Заглавные: " + str.toUpper());
}
